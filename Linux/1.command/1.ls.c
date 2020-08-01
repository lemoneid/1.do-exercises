/*************************************************************************
	> File Name: 1.ls.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月28日 星期二 18时57分33秒
 ************************************************************************/

#include "head.h"

#define MAXNAME 512
#define MAXFILE 1024

int bg_c, fg_c;

char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
void do_ls(char *);
void show_info(char *, struct stat *);
int  l_flag = 0, a_flag = 0;

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "la")) != -1) {
        switch (opt) {
            case 'l':
                l_flag = 1;
                break;
            case 'a':
                a_flag = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-la]!\n", argv[0]);
                exit(1);
        }
    }
    DBG(GREEN"<Debug>"NONE" : optind = %d\n", optind);
    argc -= optind;
    argv += optind; 
    if (argc == 0) {
        do_ls(".");
    } else {
        while (argc--) {
            DBG(GREEN"<Debug>"NONE" : argv[%d] = %s\n", argc, *argv);
            do_ls(*argv++);
        }
    }
    return 0;
}

int cmp_name(const void* _a, const void* _b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    for (int i = 0; i < strlen(a); ++i) {
        a[i] =tolower(a[i]);
    }
    for (int i = 0; i < strlen(b); ++i) {
        b[i] =tolower(b[i]);
    }

    return strcmp(a, b) < 0;
}

void update_color(mode_t mode) {
    bg_c = 0;
    fg_c = 0;
    if (mode & (S_IWGRP | S_IXUSR | S_IXOTH)) fg_c = 32;
    //if (mode & 0111)
    switch (mode & S_IFMT) {
        case S_IFDIR : 
            fg_c = 34;
            break;
        case S_IFLNK:
            fg_c = 35;
            break;
    }
}

void size_window(char *name[MAXNAME], int cnt, int *row, int *col) {
    struct winsize size;
    int len[cnt + 5], max_len = 0, total_len = 0;
    memset(len, 0, sizeof(len));
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctrl()");
        exit(1);
    }
    DBG(GREEN"<Debug>"NONE": win.row = %d, win.col = %d\n", size.ws_row, size.ws_col);
    for (int i = 0; i < cnt; ++i) {
        len[i] = strlen(name[i]);
        if (max_len < len[i]) max_len = len[i];
        // + 1;
        total_len += len[i] + 2;
    }

    if (max_len + 1 >= size.ws_col) {
        *row = cnt;
        *col = 1;
        return ;
    } 

    if (total_len <= size.ws_col) {
        *row = 1;
        *col = cnt;
        return ;
    }
    int try_begin = 0;
    for (int i = 0, tmp = 0; i < cnt; ++i) {
        tmp += (len[i] + 1);
        if (tmp >= size.ws_col) {
            try_begin = i;
            break;
        }
    }
    
    for (int i = try_begin; ;i--) {
        DBG("i = %d\n", i);
        int *wide = (int *)malloc(sizeof(int) * i);
        memset(wide, 0, 0);
        *row = ceil(cnt / i);
        int sum = 0;
        for (int x = 0; x < i; x++) {
            for (int y  = x * *row; y < (x + 1) * *row && y < cnt; y++) {
                if (wide[x] < len[y]) wide[x] = len[y];
            }
            sum +=(wide[x] + 1);
        }
        if (sum > size.ws_col) continue;
        if (sum <= size.ws_col) {
            *col = i;
            break;
        }
    }

    return ;
}

void show_files(char *name[MAXNAME], int cnt, int row, int col) {
    int wide[cnt + 5];
    memset(wide, 0, sizeof (len));
    struct stat tmp_st;
    for (int i = 0; i < col; ++i) {
        for (int j = (i * row); j < (i + 1) * row && j < cnt; j++) {
            int temp = strlen(name[j]);
            if (wide[i] < temp) wide[i] = temp;
        }
    }

    for (int i = 0; j < row; ++i) {
        for (int j = i; j < i + (row * col) && j < cnt; j += row) {
            lstat(names[j], &tmp_st);
            update_color(tmp_st);
            printf("\0333[%d;%dm%s\033[0m",fg_c, bg_c, names[j]);
        }
    }
    return ;
}

void do_ls(char *dir) {
    DIR *dirp = NULL;
    struct dirent *direntp;
    if ((dirp = opendir(dir)) == NULL) {
        if (access(dir, R_OK) == 0) {
            if (l_flag == 1) {
                struct stat tmp_st;
                lstat(dir, &tmp_st);
                show_info(dir, &tmp_st);
            } else {
                printf("%s\n", dir);
            }
            return ;
        } else {
            perror(dir);
            exit(1);
        }
    }
    char names[MAXFILE + 5][MAXNAME + 5] = {0};
    int cnt = 0;
    printf("%s:\n", dir); 
    while ((direntp = readdir(dirp)) != NULL) {
        if (direntp->d_name[0] == '.' && (a_flag == 0)) continue;
        strcpy(names[cnt++], direntp->d_name);
    }
    qsort(names, cnt, MAXNAME, cmp_name);
    chdir(dir);
    if (l_flag == 1) {
        for (int i  = 0; i < cnt; ++i) {
            struct stat temp_st;
            lstat(names[i], &temp_st);
            show_info(names[i], &temp_st);
        }
    } else {
        for (int i = 0; i < cnt; ++i) {
            int row, col;
            size_window(names, cnt, &row, &col);
            DBG(GREEN"<Debug>"NONE "row = %d , col = %d", row, col);
        }
    }
    closedir(dirp);
    printf("\n");
    return ;
}


void mode_to_str(mode_t mode, char *modestr) {
    char  pwuname[15] ,grpname[15];
    char anstime[30];
    strcpy(modestr, "----------");
    if (S_ISREG(mode)) modestr[0] = '-';
    if (S_ISDIR(mode)) modestr[0] = 'd';
    if (S_ISCHR(mode)) modestr[0] = 'c';
    if (S_ISBLK(mode)) modestr[0] = 'b';
    if (S_ISFIFO(mode)) modestr[0] = 'p';
    if (S_ISLNK(mode)) modestr[0] = 'l';
    if (S_ISSOCK(mode)) modestr[0] = 's';
    
    if (S_IRUSR & mode) modestr[1] = 'r';
    if (S_IWUSR & mode) modestr[2] = 'w';
    if (S_IXUSR & mode) modestr[3] = 'x';

    if (S_IRGRP & mode) modestr[4] = 'r';
    if (S_IWGRP & mode) modestr[5] = 'w';
    if (S_IXGRP & mode) modestr[6] = 'x';
    
    if (S_IROTH & mode) modestr[7] = 'r';
    if (S_IWOTH & mode) modestr[8] = 'w';
    if (S_IXOTH & mode) modestr[9] = 'x';

    return ;
}

void show_info(char *filename, struct stat *st) {
    char modestr[15] = {0};
    mode_to_str(st->st_mode, modestr);
    printf("%s ", modestr);
    printf("%4ld ", st->st_nlink);
    printf("%10s ", uid_to_name(st->st_uid));
    printf("%10s ", gid_to_name(st->st_gid));
    printf("%10lld", st->st_size);
    printf("%.12s ", 4 + ctime(&st->st_mtime));
    update_color(modestr[0]);
    printf("\0333[%d;%dm;%s\033[0m",bg_c, fg_c ,filename);
}

char *uid_to_name(uid_t uid) {
    struct passwd *pw_ptr;
    static char tmpstr[10] = {0};
    if ((pw_ptr == getpwuid(uid)) == NULL) {
        sprintf(tmpstr, "%d", uid);
        return tmpstr;
    } else {
        return pw_ptr->pw_name;
    }
}

char *gid_to_name(gid_t gid) {
    struct group *gr_ptr;
    static char tmpstr[10] = {0};
    if ((gr_ptr == getgrgid(gid)) == NULL) {
        sprintf(tmpstr,"%d", gid);
    } else {
        return gr_ptr->gr_name;
    }
}

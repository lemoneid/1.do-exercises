/*************************************************************************
	> File Name: 1.ls.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月28日 星期二 18时57分33秒
 ************************************************************************/

#include "head.h"

#define MAXNAME 512
#define MAXFILE 1024

int ba_c, fg_c;

char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
void do_ls(char *);
void show_info(char *, struct stat *);
int  l_flag = 0, a_flag = 0;

int main(int argc, char **argv) {
    int opt, optind = 0;
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
    DBG(GREEN"<Debug>"NONE" : optind = %d\n", opt);
    argc -= optind;
    argv += optind; 
    if (argc == 1) {
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
    return strcmp(a, b) < 0;
}

void update_color(mode_t mode) {
    bg_c = 0, fg_c = 0;
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

void do_ls(char *dir) {
    //info_size = 0;
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
            show_info(names[i], temp_st);
        }
    } else {
        for (int i = 0; i < cnt; ++i) {
            printf("%s ", names[i]);
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

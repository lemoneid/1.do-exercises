/*************************************************************************
	> File Name: ls.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月25日 星期六 19时03分32秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

void do_ls(char *);
void show_info(char *, struct stat *);
int  l_flag = 0, a_flag = 0;
int info_size = 0;
struct info {
    char filename[255];
    char other[4000];
} info[10000];

void sort(int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(info[j].filename + 6, info[ind].filename + 6) < 0) ind = j;
        }
        char temp1[20] = {0}, temp2[100] = {0};
        strcpy(temp1, info[i].filename);
        strcpy(info[i].filename, info[ind].filename);
        strcpy(info[ind].filename, temp1);

        strcpy(temp2, info[i].other);
        strcpy(info[i].other, info[ind].other);
        strcpy(info[ind].other, temp2);
    }
    return ;
}

void showout(int n, char *dir, int flag) {
    printf("\33[31;1m%s:\033[0m\n", dir);
    for (int i = 0; i < n; ++i) {
        if (flag) {
            printf("%s ", info[i].other);
        }
        printf("%s", info[i].filename);
        printf("\n");
    }
    return ;
}

void clear(int info_size) {
    for (int i = 0; i < info_size; ++i) {
        memset(info[i].filename, 0, sizeof(info[i].filename));
        memset(info[i].other, 0, sizeof(info[i].other));
    }
    return ;
}

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
    int flag  = 0;
    if (argc == 1) {
        do_ls(".");
    } else {
        while (--argc) {
            argv++;
            if (*argv[0] != '-') {
                do_ls(*argv);
                flag = 1;
            }
        }
    }
    if (!flag) do_ls(".");
    return 0;
}

void do_ls(char *dir) {
    info_size = 0;
    DIR *dirp = NULL;
    struct dirent *direntp;
    if ((dirp = opendir(dir)) == NULL) {
        perror("opendir()");
        exit(1);
    }
    while ((direntp = readdir(dirp)) != NULL) {
        if ((a_flag == 0) && (direntp->d_name[0] == '.')) continue;
        struct stat st;
        char filename[100] = {0};
        strcpy(filename, dir);
        strcat(strcat(filename, "/"), direntp->d_name);
        if (lstat(filename, &st) < 0) {
            perror(direntp->d_name);
            exit(1);
        } else {
            show_info(direntp->d_name, &st);
        }
    }
    sort(info_size);
    if (l_flag == 0) {
        showout(info_size, dir, 0);
    } else {
        showout(info_size, dir, 1);
    }
    closedir(dirp);
    clear(info_size);
    printf("\n");
    return ;
}


void show_info(char *filename, struct stat *st) {
    char modestr[15] = {0}, pwuname[15] ,grpname[15];
    char anstime[30];
    strcpy(modestr, "----------");
    if (S_ISDIR(st->st_mode)) modestr[0] = 'd';
    if (S_ISCHR(st->st_mode)) modestr[0] = 'c';
    if (S_ISBLK(st->st_mode)) modestr[0] = 'b';
    //if (S_ISREG(st->st_mode)) modestr[0] = '';
    if (S_ISFIFO(st->st_mode)) modestr[0] = 'f';
    if (S_ISLNK(st->st_mode)) modestr[0] = 'l';
    if (S_ISSOCK(st->st_mode)) modestr[0] = 's';
    
    if (S_IRUSR & st->st_mode) modestr[1] = 'r';
    if (S_IWUSR & st->st_mode) modestr[2] = 'w';
    if (S_IXUSR & st->st_mode) modestr[3] = 'x';
    if (S_IRGRP & st->st_mode) modestr[4] = 'r';
    if (S_IWGRP & st->st_mode) modestr[5] = 'w';
    if (S_IXGRP & st->st_mode) modestr[6] = 'x';
    if (S_IROTH & st->st_mode) modestr[7] = 'r';
    if (S_IWOTH & st->st_mode) modestr[8] = 'w';
    if (S_IXOTH & st->st_mode) modestr[9] = 'x';
    //if (S_ & st->st_mode) modestr[] = '';
    struct passwd *pwu = getpwuid(st->st_uid);
    strcpy(pwuname, pwu->pw_name);
    struct group *grp = getgrgid(st->st_gid);
    strcpy(grpname, grp->gr_name);
    char *mtime = strdup(4 + ctime(&(st->st_mtime)));

    sprintf(info[info_size].other,"%s %3d %6s %6s %9.1lfk %.12s", modestr, (int)st->st_nlink ,pwuname, grpname, st->st_size * 1.0 / 1024, mtime);
    if (modestr[0] == 'd') {
        sprintf(info[info_size].filename,"\033[34;1m%s\033[0m", filename);
    }else if(modestr[3] == 'x'){
        sprintf(info[info_size].filename,"\033[32;1m%s\033[0m", filename);
    } else {
        sprintf(info[info_size].filename,"\033[37;0m%s\033[0m", filename);
    }   
    info_size++;
}

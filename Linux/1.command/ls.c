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
    if (argc == 1) {
        do_ls(".");
    } else {
        while (argc--) {
            argv++;
            if (*argv[0] == '-') continue;
            if (*argv[0] == '/') do_ls(*argv);
        }
    }
    return 0;
}

void dostat(char *filename, char *dir) {
    char pwdname[1000];
    strcpy(pwdname, filename);
    if (strcmp(dir, ".") ==0) {
        strcpy(pwdname, filename);
    }  else if (strcmp(dir, "/") == 0) {
        strcat(pwdname, filename);
    } else {
        strcat(strcat(pwdname, "/"), filename);
    }
}

void do_ls(char *dir) {
    DIR *dirp = NULL;
    struct dirent *direntp;
    if ((dirp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(1);
    }
    while ((direntp = readdir(dirp)) != NULL) {
        if ((a_flag == 0) && (direntp->d_name[0] == '.')) continue;
        if (l_flag == 0) {
            printf("%s ", direntp->d_name);
        } else {
            struct stat st;
            char filename[1000] = {0};
            strcpy(filename, dir);
            strcat(strcat(filename, "/"), direntp->d_name);
            if (lstat(filename, &st) < 0) {
                perror("lstat");
                exit(1);
            } else {
                show_info(direntp->d_name, &st);
            }
        }
    }
    printf("\n");
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
    if (S_ISLNK(st->st_mode)) modestr[0] = 's';
    if (S_ISSOCK(st->st_mode)) modestr[0] = 'l';
    
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
    printf("%s %3ld %s %s %9ld %.12s ", modestr, st->st_nlink ,pwuname, grpname, st->st_size, mtime);
    if (modestr[0] == 'd') {
        printf("\033[34;1m%s\033[0m\n", filename);
    }else if(modestr[3] == 'x'){
        printf("\033[32;1m%s\033[0m\n", filename);
    } else {
        printf("%s\n", filename);
    }   
}

/*************************************************************************
	> File Name: 1.c
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月06日 星期四 11时16分24秒
 ************************************************************************/

#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
        char buf[50] = {"file descriptor demo"};
        FILE *myfile;

        myfile = fopen("test","w+");
        if(!myfile){
                printf("error: openfile failed!\n");
        }
        printf("The openfile's descriptor is %d\n", myfile->_fileno);
        if(write(myfile->_fileno, buf,strlen(buf))<0){
                perror("error: write file failed!\n");
                exit(1);
        }else{
                printf("writefile successed!\n");
        }

        exit(0);
}

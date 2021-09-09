/*************************************************************************
	> File Name: 4.tee.c
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月09日 星期四 09时05分32秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage : %s <file>\n", argv[0]);
        return 1;
    }
    int filefd = open(argv[1], O_CREAT | O_WRONLY | OTRUNC, 0666);
    assert(filefd > 0);
    int pipefd_stdout[2];
    int ret = pipe(pipefd_stdout);
    assert(ret != -1);
    int pipefd_file[2];
    ret = pipe(pipefd_file);
    assert(ret != -1);
    ret = splice(STDIN_FILENO, NULL, pipefd_stdout[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
    assert(ret != -1);
    ret = tee(pipefd_stdout[0], pipefd_file[1], SPLICE_F_NONBLOCK);
    assert(ret != -1);
    ret = splice(pipefd_file[0], NULL, STDOUT_FILENO, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE);
    assert(ret != -1);
    ret = splice(pipefd_stdout[0], NULL, STDOUT_FILENO, NULL, 32768,SPLICE_F_MORE|SPLICE_F_MOVE);
    assert(ret!=-1);
    close(filefd);
    close(pipefd_stdout[0]);
    close(pipefd_stdout[1]);
    close(pipefd_file[0]);
    close(pipefd_file[1]);
    return 0;
}

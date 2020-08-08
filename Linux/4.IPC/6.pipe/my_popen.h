/*************************************************************************
	> File Name: my_popen.h
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月04日 星期二 14时48分41秒
 ************************************************************************/

#ifndef _MY_POPEN_H
#define _MY_POPEN_H

FILE *m_popen(const char *cmd, const char *type);
int m_pclose(FILE *fp);

#endif

/*************************************************************************
	> File Name: 212.排序名单.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 19时58分42秒
 ************************************************************************/

#include <iostream>
#include <malloc.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int max_n = 100;

char *str[max_n + 5];

bool cmp(char *s1, char *s2) {
    return strncmp(s1, s2, 8) < 0;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        str[i] = (char *) malloc (sizeof(char) * 20);
    }
    for (int i = 0; i < 10; ++i) {
        cin >> str[i];
    }
    cout << str << endl;
    cout << str + 1 << endl;
    printf("%s ", &str[0][0]);cout << endl;
    printf("%s ", &str[1][0]);cout << endl;
    cout << sizeof(str[1]) << endl;
    cout << sizeof (str) << endl;
    sort(str, str + 10, cmp);
    for (int i = 0; i < 10; ++i) {
        cout << str[i] << endl;
    }
    return 0;
}

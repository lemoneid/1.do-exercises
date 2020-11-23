/*************************************************************************
	> File Name: oj-717.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 13时36分44秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

char str[1005];
unordered_map<char, char> mmap;
int main() {
    scanf("%[^\n]s", str);
    getchar();
    for (int i = 0; i < 26; ++i) {
        char ch;
        scanf("%c", &ch);
        mmap[ch] = i + 'a';
    }
    int i = 0;
    while (str[i]) {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        str[i] = mmap[str[i]];
        i++;
    }
    printf("%s\n", str);
    return 0;
}

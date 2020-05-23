/*************************************************************************
	> File Name: EP13.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 14时27分49秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

const int max_n = 54;

char str[max_n + 5];
int ans[max_n + 5] = {1,0};

int main() {
    for (int i = 0; i < 100; ++i) {
        scanf("%s", str);
        int len = strlen(str);
        if (ans[0] < len) ans[0] = len;
        for (int j = 0; j < len; ++j) {
            ans[len - j] += (str[j] - '0');
        }
        for (int j = 1; j <= ans[0]; ++j) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; --i) {
            cout << ans[i];
    }
    cout << endl;
    return 0;
}

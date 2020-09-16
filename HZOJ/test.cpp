<<<<<<< HEAD
/*************************************************************************
	> File Name: oj-470-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年08月13日 星期四 21时56分22秒
 ************************************************************************/

=======
>>>>>>> e90f808277c560ccf82e32aba3c1aad0144013e6
#include <iostream>
#include <cstring>
using namespace std;
char to_10[128];
int num[500005];
int dp[500005];
void init() {
    int x = 0;
    for (int i = '0'; i <= '9'; ++i) {
        to_10[i] = x++;
    }

<<<<<<< HEAD
    for (int i = 'A'; i <= 'Z'; ++i) {
        to_10[i] = x++;
    }
    return ;
}

int main() {
    init();
    int cnt = 0, ans = 0;
    string s;
    while (cin >> s) {
        for (int i = 0; i < 5; ++i) {
            num[cnt] = num[cnt] * 10 + to_10[s[i]];
=======
#define SIZE 1000

int Sub(int *p1, int len1, int *p2, int len2) {
    if (len1 < len2) return -1;
    if (len1 == len2) {
        for (int i = len1 -1; i >= 0; --i) {
            if (p1[i] == p2[i]) continue;
            if (p1[i] > p2[i]) {
                break;
            } else {
                return -1;
            }
        }
    }
    for (int i = 0; i <= len1 - 1; i++) {
        p1[i] -= p2[i];
        if (p1[i] < 0) {
            --p1[i + 1];
            p1[i] += 10;
        }
    }
    for (int i = len1 - 1; i >= 0; --i) {
        if (p1[i]) {
            return (i + 1);
        }
    }
    return 0;
}

void Div(char *num1, char *num2, int *ans) {

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int dValue, tmp, len = 0;
    int num_a[SIZE + 5] = {0};
    int num_b[SIZE + 5] = {0};
    
    for (int i = 0, j = len1 - 1; j >= 0; ++i, --j) num_a[i] = num1[j] - '0';
    for (int i = 0, j = len2 - 1; j >= 0; ++i, --j) num_b[i] = num2[j] - '0';

    if (len1 < len2) {
        cout << num1 << endl;
        return ;
    }
    
    dValue = len1 - len2;
    for (int i = len1 - 1; i >= 0; --i) {
        if (i >= dValue) num_b[i] = num_b[i - dValue];
        else num_b[i] = 0;
    }
    
    len2 = len1;
    for (int i = 0; i <= dValue; ++i) {
        while ((tmp = Sub(num_a, len1, num_b + i, len2 - i)) >= 0) {
            len1 = tmp;
            ans[dValue - i] += 1;
>>>>>>> e90f808277c560ccf82e32aba3c1aad0144013e6
        }
        if (cnt > 0) {
            num[cnt - 1] -= num[cnt];
        } 
        cnt++;
    }
<<<<<<< HEAD
    cout << " - " << endl;
    for (int i = 0; i < cnt - 1; ++i) {
        cout << num[i] << endl;
    }
    for (int i = 1; i < cnt - 1; ++i) {
        num[i] += num[i - 1];
    }
    cout << " sum " << endl;
    for (int i = 0; i < cnt - 1; ++i) {
        cout << num[i] << endl;
    }
    cout << "dp" << endl;

    ans = abs(num[0]);
    dp[0] = num[0];
    cout << ans << endl;
    for (int i = 1; i < cnt - 1; ++i) {
        if (abs(num[i]) < abs(dp[i - 1] + num[i])) {
            dp[i] = num[i];
        } else {
            dp[i] = dp[i -1] + num[i];
        }
        cout << dp[i] << endl;
        ans = min(ans, abs(dp[i]));
    }
    cout << ans << endl;
    return 0;
=======

    if (len1 == 0) {
        cout << 0 << endl;
        return ;
    }
    for (int i = len1 - 1; i >= 0; --i) {
        cout << num_a[i];
    }
    cout << endl;
    return ;
}

int main() {
    char num1[SIZE + 5] = {0}, num2[SIZE + 5] = {0};
    int ans[SIZE + 5] = {0};
    cin >> num2 >> num1;
    // num2 / num1
    Div(num1, num2, ans);
>>>>>>> e90f808277c560ccf82e32aba3c1aad0144013e6
}


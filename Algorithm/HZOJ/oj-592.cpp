/*************************************************************************
	> File Name: oj-592.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sat 15 Aug 2020 10:33:53 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int zero[70], to_10[256], a[6] = {1, 2, 4, 8, 16, 32};
char s[100005];

void init() {
    for (int i = 63; i >= 0; --i) {
        int t = i;
        for (int j = 5; j >= 0; --j) {
            if (t >= a[j]) {
                zero[i]++;
                t -= a[j];
            }
        }
        zero[i] = 6 - zero[i];
    }

    int id = 0;
    for (char i = '0'; i <= '9'; ++i) {
        to_10[i] = id++;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        to_10[i] = id++;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        to_10[i] = id++;
    }
    to_10['-'] = id++;
    to_10['_'] = id;
    return ;
}

int main() {
    init();
    cin >> s;
    long long ans = 1;
    for (int i = 0; s[i]; ++i) {
        for (int j = 0; j < zero[to_10[s[i]]]; ++j) {
            ans  = ans * 3 % 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}

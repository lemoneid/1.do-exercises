/*************************************************************************
	> File Name: oj-170-2.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月26日 星期二 18时22分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 100

string str[max_n + 5];

void output(string *str, int n) {
    for (int i = 0; i < n; ++i) {
        cout << str[i] << endl;
    }
}

void solve(string *str, int n) {
    for (int i = 0; i < n; ++i) {
        while (str[i].find("Ban_smoking") != string::npos) {
            int pos = str[i].find("Ban_smoking");
            str[i].replace(pos, 11, "No_smoking");
        }
    }
    output(str, n);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> str[i];
    solve(str, n);
    return 0;
}

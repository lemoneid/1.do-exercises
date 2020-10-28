/*************************************************************************
	> File Name: oj-505.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月11日 星期四 07时13分33秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define max_n 100000

string num[max_n + 5];

bool cmp (string a, string b) {
    return (a + b) > (b + a);
}

int main() {
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) cin >> num[i];
    sort(num, num + cnt, cmp);
    for (int i = 0; i < cnt; ++i) 
        cout << num[i];
    cout << endl;
    return 0;
}

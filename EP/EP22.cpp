/*************************************************************************
	> File Name: EP22.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年06月07日 星期日 14时13分36秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include "input_22"
using namespace std;

bool cmp(const string s1, const string s2) {
    //if (s1.compare(s2) < 0) return 1;
    //return 0;
    return s1 < s2;
}

int calc(string s1) {
    int sum = 0;
    for (int i = 0; i < s1.length(); ++i) {
        sum += s1[i] - 'A' + 1;
    }
    return sum;
}

int main() {
    int len = 5163;
    long long ans = 0;
    sort(name, name + len, cmp);
    for (int i = 0; i < len; ++i) {
        ans += (i + 1) * calc(name[i]);
    }
    cout << ans << endl;
    return 0;
}

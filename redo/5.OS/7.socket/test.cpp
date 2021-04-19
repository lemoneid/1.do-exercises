/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月12日 星期一 22时53分35秒
 ************************************************************************/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAX_N 1000

int main() {
    int n, temp, ans = 0;
    vector <int> vec;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        set <int> se;
        int mmax = vec[i], mmin = vec[i];
        for (int j = i; j < n; ++j) {
            if (se.count(vec[i])) {
                break;
            }
            mmax = max(vec[j], mmax);
            mmin = min(vec[j], mmin);
            int len = j - i + 1;
            if ( mmax - mmin + 1 == len) {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << endl;
    return 0;
}


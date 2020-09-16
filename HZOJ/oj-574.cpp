/*************************************************************************
	> File Name: oj-574.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri 14 Aug 2020 10:28:38 PM CST
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

set <int> se;

void do_insert(int x) {
    if (se.find(x) == se.end()) {
        se.insert(x);
    } else {
        se.erase(x);
        do_insert(x + 1);
    }
}

int main() {
    int n, x;
    cin >> n;
    do_insert(-1);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        do_insert(x);
    }

    set<int>::iterator it1, it2;
    it1 = it2 = se.begin();
    it2++;
    int ans = 0;
    while (it2 != se.end()) {
        ans += *it2 - *it1 - 1;
        ++it1;
        ++it2;
    }

    cout << ans << endl;
    return 0;
}

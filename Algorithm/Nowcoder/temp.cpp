/*************************************************************************
	> File Name: temp.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月07日 星期三 20时17分18秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    vector<int> vec;
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}

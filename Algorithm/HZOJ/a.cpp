/*************************************************************************
	> File Name: a.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月22日 星期二 18时48分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

map <int, int> mmap;

int main() {
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        mmap[temp] = i + 1;
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        cout << mmap[temp] << endl;
    }

    return 0;
}

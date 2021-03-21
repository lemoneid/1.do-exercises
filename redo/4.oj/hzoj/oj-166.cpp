/*************************************************************************
	> File Name: oj-166.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 13时18分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a;
    cin >> n;
    cin >> b;
    cout << min(a.size(), (size_t)100) << endl;
    a.insert(n - 1, b);
    cout << a.length() - a.rfind('x') << endl;
    return 0;
}

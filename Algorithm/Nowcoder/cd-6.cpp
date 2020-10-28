/*************************************************************************
	> File Name: cd-6.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月14日 星期一 14时05分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

int main() {
    int n, x;
    stack <int> chu;
    stack <int> ru;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "add") {
            cin >> x;
            ru.push(x);
            continue;
        }
        if (chu.empty()) {
            while (!ru.empty()) {
                chu.push(ru.top());
                ru.pop();
            }
        }
        if (str == "peek") {
           cout << chu.top() << endl; 
        } else {
            chu.pop();
        }

    }
    return 0;
}

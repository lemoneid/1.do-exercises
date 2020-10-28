/*************************************************************************
	> File Name: cd-5.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月14日 星期一 13时55分21秒
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
    stack <int> stackData;
    stack <int> stackMin;
    string str;
    int n, x;
    cin >> n;
    while (n--) {
        cin >> str;
        if (str == "push") {
            cin >> x;
            stackData.push(x);
            if (stackMin.empty()) {
                stackMin.push(x);
                continue;
            } 
            if (stackMin.top() >= x) {
                stackMin.push(x);
            }
        } else if (str == "getMin") {
            if (stackMin.empty()) {
                cout << "stackMin is empty" << endl;
                continue;
            }
            cout << stackMin.top() << endl;
        } else if (str == "pop") {
            if (stackData.top() == stackMin.top()) {
                stackMin.pop();
            }
            stackData.pop();
        }
    }

    return 0;
}

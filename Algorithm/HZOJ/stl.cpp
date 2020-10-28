/*************************************************************************
	> File Name: stl.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Tue 18 Aug 2020 04:29:59 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack <int> sta;
    for (int i = 1; i < 5; ++i) {
        sta.push(i);
    }

    cout << "size : " << sta.size() << endl;
    cout << "top : "<< sta.top() << endl;
    sta.pop();
    while (!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }
    cout << "queue -------" << endl;
}


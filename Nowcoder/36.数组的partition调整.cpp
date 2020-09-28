/*************************************************************************
	> File Name: 36.数组的partition调整.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月26日 星期六 20时06分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 100000

int num[MAX_N + 5];
int n;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int l = -1, idx = 0, r = n;
    while (idx < r) {
        if (num[idx] == 0) {
            swap(num[++l], num[idx++]); // idx++ !!!
        } else if (num[idx] == 2){
            swap(num[--r], num[idx]);
        } else {
            idx++;
        }
    }
    for (int i = 0; i < n; ++i) {
        i && cout << " ";
        cout << num[i];
    }
    return 0;
}

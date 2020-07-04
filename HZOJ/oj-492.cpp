/*************************************************************************
	> File Name: oj-492.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年07月03日 星期五 11时09分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[31];

int main() {
    int k;
    cin >> k;
    arr[1] = 0, arr[2] = arr[3] = 1;
    for (int i = 4; i <= k; ++i) {
        if (i & 1) arr[i] = arr[i -1];
        else arr[i] = 2 * arr[i - 2] + 1;
    }
    cout << arr[k] << endl;
    return 0;
}

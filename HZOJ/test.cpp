/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月28日 星期四 18时48分19秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 1000000;

int is_val(int n, int key) {
    int sum = 0;
    int temp = n;
    while (temp) {
        sum = sum * key  + temp % key;
        temp /= key;
    }
    return sum == n;
}
int main() {
    long long sum = 0;
    for (int i = 1; i < max_n; ++i) {
        if(is_val(i, 10) && is_val(i, 2)) sum += i;
    }
    cout << sum << endl;
    return 0;
}

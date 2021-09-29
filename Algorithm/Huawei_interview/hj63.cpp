/*************************************************************************
	> File Name: hj63.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月28日 星期二 17时21分57秒
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
    string s;
    int n;
    while (cin >> s >> n) {
        int size = s.size();
        vector<int> arr(size, 0);
        vector<int> sum(size, 0);
        for (int i = 0; i < size; i++) {
            if (s[i] == 'G' || s[i] == 'C') arr[i] = 1;
        }
        for (int i = 0; i < size - n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i] += arr[i + j];
            }
        }
        int max = 0;
        int pos = 0;
        for (int i = 0; i < size - n; i++) {
            if (sum[i] > max) {
                max = sum[i];
                pos = i;
            }
        }
        cout << s.substr(pos, n) << endl;
    }


    return 0;
}

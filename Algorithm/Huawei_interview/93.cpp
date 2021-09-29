/*************************************************************************
	> File Name: 93.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 16时35分47秒
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
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr;
        int target = 0;
        int sum = 0;
        for (int i = 0, val; i < n; i++) {
            cin >> val;
            if (val % 5 == 0) target += val;
            else if (val % 3 == 0) target -= val;
            else arr.push_back(val), sum += val;
        }
        target = abs(target);
        if ((sum + target) % 2 == 1) {
            cout << "false" << endl;
            continue;
        }
        int big = (sum + target) / 2;
        int flag = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int cur = 0;
            for (int j = i; j < arr.size(); j++) {
                cur += arr[i];
                if (cur == big) {
                    flag = 1;
                    break;
                }
                if (cur > big) break;
            }
            if (flag == 1) break;
        }
        if (flag) cout << "true";
        else cout<< "false" ;
        cout << endl;
    }
    return 0;
}

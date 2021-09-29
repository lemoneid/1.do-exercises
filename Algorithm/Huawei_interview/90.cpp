/*************************************************************************
	> File Name: 90.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 16时25分29秒
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
    string input;
    while (getline(cin, input)) {
        vector<string> result;
        int cur = 0, max_len = 0;
        int size = input.size(), pre = 0;
        for (int i = 0; i < size; i++) {
            if (input[i] < '0' || input[i] > '9') continue;
            pre = i;
            while (i < size && input[i] >= '0' && input[i] <= '9') {
                i++;
            }
            cur = i - pre;
            if (cur > max_len) {
                max_len = cur;
                result.clear();
                result.push_back(input.substr(pre, cur));
            } else if (cur == max_len) {
                result.push_back(input.substr(pre, cur));
            }
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << "," << result[0].size() << endl;
    }
    return 0;
}

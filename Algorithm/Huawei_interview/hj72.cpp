/*************************************************************************
	> File Name: hj72.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月29日 星期三 13时36分20秒
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
        int pre = 0;
        vector<string> res;
        input = ' ' + input + ' ';
        int size = input.size();
        for (int i = 0;  i < size; i++) {
            if (input[i] == '"') {
                pre = ++i;
                while (i < size && input[i] != '"') i++;
                string s = input.substr(pre, i - pre);
                res.push_back(input.substr(pre, i - pre));
            } else if (input[i] == ' ' && i < size - 1 && input[i + 1] != '"') {
                pre = ++i;
                cout << pre << endl;
                while (i < size && input[i + 1] != ' ') i++;
                string s = input.substr(pre, i - pre + 1);
                cout << "pre : " << pre << " " <<  s << endl;
                res.push_back(input.substr(pre, i - pre + 1));
            } else {
                cout << i << " : " << input[i] << endl;
            }
        }
        cout << res.size() << endl;
        for (auto &cur : res) cout << cur << endl;
    }
    return 0;
}

/*************************************************************************
	> File Name: HJ19.简单错误记录.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月18日 星期六 18时30分36秒
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
#include <unordered_map>
using namespace std;


string get_name(string path) {
    path = path.substr(path.rfind('\\') + 1);
    if (path.size() > 16) {
        path = path.substr(path.size() - 16);
    }
    return path;

}

int main() {
    string path;
    vector<string> res;
    unordered_map<string, int> mmap;
    int num;
    while (cin >> path >> num) {
        string name = get_name(path) + ' ' + to_string(num);
        if (mmap.find(name) == mmap.end()) {
            mmap[name] = 1;
            res.push_back(name);
        } else {
            mmap[name]++;
        }
    }
    int i = res.size() > 8 ? res.size() - 8 : 0;
    for (; i < res.size(); i++) {
        cout << res[i] << " " << mmap[res[i]] << endl;
    }

    return 0;
}

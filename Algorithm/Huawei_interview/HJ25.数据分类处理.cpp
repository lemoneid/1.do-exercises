/*************************************************************************
	> File Name: HJ25.数据分类处理.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月19日 星期日 21时28分01秒
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

string string_sort(string str) {
    int len = str.size();
    vector<char> arr;
    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < len; i++) {
            if ((str[i] - 'a' == j) ||  (str[i] - 'A' == j)) {
                arr.push_back(str[i]);
            }
        }
    }
    for (int i = 0, k = 0; (i < len) && (k < arr.size()); i++) {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = arr[k++];
        }
    }
    return str;
}

int main() {

    string str;
    while (getline(cin, str)) {
        cout << string_sort(str) << endl;
    }
    return 0;
}

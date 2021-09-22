/*************************************************************************
> File Name: HJ18.识别有效的IP地址和掩码并进行分类统计.cpp
> Author: yanzw
> Mail: yanzw@pm.me
> Created Time: 2021年09月18日 星期六 16时42分37秒
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
#include<sstream>
using namespace std;

bool is_ip(string ip) {
    int j = 0;
    istringstream iss(ip);
    string seg;
    while (getline(iss, seg, '.')) {
        if (++j > 4 || seg.empty() || stoi(seg) > 255) {
            return false;
        }
    }
    return j == 4;
}

bool is_private(string ip) {
    istringstream iss(ip);
    string seg;
    vector<int> arr;
    while(getline(iss, seg, '.'))  arr.push_back(stoi(seg));
    if (arr[0] == 10) return true;
    if (arr[0] == 172 && arr[1] >= 16 && arr[1] <= 31) return true;
    if(arr[0] == 192 && arr[1] == 168) return true;
    return false;
}


bool is_mask(string ip) {
    istringstream iss(ip);
    string seg;
    unsigned int b = 0;
    while (getline(iss, seg, '.')) b = (b << 8) + stoi(seg);
    if (b == 0) return false;
    b = ~b + 1;
    if (b == 1) return false;
    if ((b & (b - 1)) == 0) return true;
    return false;
}

int main() {
    string input;
    int a = 0, b = 0, c = 0, d = 0, e = 0, err = 0, p = 0;

    #ifdef _D
    #endif

    while (cin >> input) {
        istringstream iss(input);
        string add;
        vector<string> arr;
        while (getline(iss, add, '~')) arr.push_back(add);
        if (!is_ip(arr[0])) err++;
        int first = stoi(arr[0].substr(0,arr[0].find_first_of('.')));
        if (first == 127) continue;
        if (!is_ip(arr[1]) || !is_mask(arr[1])) err++;
        else {
            if(is_private(arr[0])) p++;
            if(first > 0 && first < 127) a++;
            else if(first > 127 && first <192) b++;
            else if(first > 191 && first <224) c++;
            else if(first > 223 && first <240) d++;
            else if(first > 239 && first <256) e++;
        }
        #ifdef _D
        cout << input << " ---- : " <<  a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << p << endl;
        cout << endl;
        #endif
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << err << " " << p << endl;
    return 0;
}

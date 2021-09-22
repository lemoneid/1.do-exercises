/*************************************************************************
> File Name: test.cpp
> Author: yanzw
> Mail: yanzw@pm.me
> Created Time: 2021年09月20日 星期一 16时39分24秒
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

auto is_in(int a, int b) {
    return [=](int x) {
        return a <= x && x <= b;
    };
}

auto OR = [](auto u, auto v) {
    return [=](int x) {
        return u(x) || v(x);
    };
};
auto is_little = is_in('a', 'z');
auto is_upper = is_in('A', 'Z');
auto is_digit = is_in('0', '9');
auto is_alpha = OR(is_little, is_upper);

int main() {
    string str;
    while (cin >> str) {
        string res;
        for(auto x : str)
        {
            if(isdigit(x))
            {
                if(x == '9') res.push_back('0');
                else res.push_back(x+1);
            }
            else
            {
                if(x == 'Z') res.push_back('a');
                else if(x == 'z') res.push_back('A');
                else if(islower(x)) {x++; res.push_back(x-32);}
                else {x++; res.push_back(x+32);}
            }
        }
        cout << res << endl;
        cin >> str;
        res = "";
        for(auto x : str)
        {
            if(isdigit(x))
            {
                if(x == '0') res.push_back('9');
                else res.push_back(x-1);
            }
            else
            {
                if(x == 'a') res.push_back('Z');
                else if(x == 'A') res.push_back('z');
                else if(x >= 'a' && x <= 'z') {x -= 32; res.push_back(x-1);}
                else {x += 32; res.push_back(x-1);}
            }
        }
        cout << res << endl;
    }
    return 0;
}

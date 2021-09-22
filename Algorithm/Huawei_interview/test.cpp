/*************************************************************************
	> File Name: test.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月21日 星期二 21时32分34秒
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

class BigInt : public vector<int> {
public : 
    BigInt(string s) {
        if (s.empty()) {
            push_back(0);
            normal();
        } else {
            for (int i = s.size() - 1; i >= 0; i--) {
                push_back(s[i] - '0');
            }
            normal();
        }
    }
    BigInt(int x = 0) {
        push_back(x);
        normal();
    }
    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        for (int i = 0; i < a.size(); i++) {
            if (i < ret.size()) ret[i] += a[i];
            else ret.push_back(a[i]);
        }
        ret.normal();
        return ret;
    }
    void normal() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1)  += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];
    }
    return out;
}


int main() {
    string a, b;
    while (cin >> a >> b) {
        BigInt A(a), B(b);
        cout << (A + B) << endl;
    }
    return 0;
}

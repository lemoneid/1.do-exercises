/*************************************************************************
	> File Name: BigInt.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月15日 星期二 19时03分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class BigInt : vector<int>{
public : 
    BigInt() {push_back(0);};
    BigInt(const string &obj) {
        for (int i = obj.size() - 1; i >= 0; --i) {
            push_back(obj[i] - '0');
        }
    }
    BigInt operator*(const BigInt &obj) {
        BigInt ret;
        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < obj.size(); ++j) {
                if (i + j == ret.size()) ret.push_back(0);
                ret[i + j] += at(i) * obj[j];
            }
        }
        ret.process_digit();
        return ret;
    }
    void process_digit() {
        while (size() > 1 && at(size() - 1) == 0) pop_back(); 
        for (int i = 0; i < size(); ++i) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
    }
    friend ostream &operator<<(ostream &, const BigInt &);
};
ostream &operator<<(ostream &out, const BigInt &obj) {
    for (int i = obj.size() - 1; i >= 0; --i) out << obj[i];
    return out;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << BigInt(a) * BigInt(b) << endl;
    return 0;
}

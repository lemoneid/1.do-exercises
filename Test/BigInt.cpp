/*************************************************************************
	> File Name: BigInt.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月16日 星期三 09时28分36秒
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

class BigInt : std::vector<int> {
public :
    BigInt() {}
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    BigInt operator+(const BigInt &obj) {
        BigInt ret = *this;
        for (int i = 0; i < obj.size(); ++i) {
            if (i == ret.size()) ret.push_back(0); 
            ret[i] += obj[i];
        }
        process_digit();
        return ret;
    }
    void process_digit() {
        for (int i = 0; i < size(); ++i) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
    friend ostream &operator<<(ostream &, const BigInt &);
};

ostream &operator<<(ostream &out, const BigInt &obj) {
    out << "<class BigInt> ";
    for (int i = obj.size() - 1; i >= 0; --i) out << obj[i];
    return out;
}

int main() {
    BigInt a = 12;
    BigInt b(12312);
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    BigInt c = a + b;


    return 0;
}

/*************************************************************************
	> File Name: oj-183.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月21日 星期六 14时54分29秒
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
#define MOD 1000000007
#define MAX_N 20
struct BigInt: public vector<int> {
    BigInt(int x = 0) {
        push_back(x);
        normal();
    }

    BigInt operator+(const BigInt &a) {
        BigInt ret(*this);
        for (int i = 0; i < a.size(); ++i) {
            if (i < ret.size()) ret[i] += a[i];
            else ret.push_back(a[i]);
        }
        ret.normal();
        return ret;
    }
    void normal() {
        for (int i = 0; i < size(); ++i) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

int main() {

    return 0;
}

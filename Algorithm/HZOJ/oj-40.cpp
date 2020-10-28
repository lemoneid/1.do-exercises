/*************************************************************************
	> File Name: oj-40.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri 21 Aug 2020 09:46:53 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct BigInt : vector<int> {
    BigInt(int x) {
        push_back(x);
        normal();
    }
    BigInt operator+(const BigInt &b) {
        BigInt ret = *this;
        for (int i = 0; i < b.size(); ++i) {
            if (i < ret.size()) {
                ret[i] += b[i];
            } else {
                ret.push_back(b[i]);
            }
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
ostream &operator<<(ostream &out,const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; --i) {
        out << a[i];
    }
    return out;
}
int main() {
    int n;
    cin >> n;
    BigInt num[4] = {0, 0, 1, 1};
    int k = 4;
    while (k <= n) {
        num[k % 4] = num[ (k - 2) % 4] + num[ (k - 3) % 4];
        k++;
    }
    cout << num[n % 4]; 
    return 0;
}

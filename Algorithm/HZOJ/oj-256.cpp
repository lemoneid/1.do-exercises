/*************************************************************************
	> File Name: oj-256.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年10月27日 星期二 21时03分31秒
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
#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5];
int ind[MAX_N + 5];

bool cmp(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}

struct BigInt : public vector<int>{
    BigInt(int x) {
        push_back(x);
        normal();
    }

    BigInt(vector<int> ret) {
        assign(ret.begin(), ret.end());
    }
    
    BigInt operator/(int x) {
        int temp = 0, i = size() - 1;
        while (i >= 0 && temp * 10 + at(i) < x) temp = temp * 10 + at(i--);
        if (i < 0) return 0;
        //BigInt(0)
        vector<int> ret(i + 1);
        while (i >= 0) {
            temp = temp * 10 + at(i);
            ret[i] = temp / x;
            temp %= x;
            i--;
        }
        return ret;
    }

    bool operator>(BigInt &obj) {
        if (size() - obj.size()) return size() > obj.size();
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) - obj[i]) return at(i) > obj[i];
        }
        return false;
    }

    void operator*=(int x) {
        for (int i = 0; i < size(); ++i) {
            at(i) *= x;
        }
        normal();
        return ;
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

ostream &operator<<(ostream &out, const BigInt &obj) {
    for (int i = obj.size() - 1; i >= 0; i--) {
        out << obj[i];
    } 
    return out;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) cin >> a[i] >> b[i], ind[i] = i;
    sort(ind + 1, ind + 1 + n, cmp);
    BigInt p = a[ind[0]], ans = 0;
    for (int i = 1; i <= n; ++i) {
        BigInt temp = p / b[ind[i]];
        if (temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}

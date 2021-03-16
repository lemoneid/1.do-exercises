/*************************************************************************
	> File Name: 1.BigInt.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月10日 星期三 21时27分34秒
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

struct Data {
    int a, b;
    bool operator<(const Data &obj) const {
        return a * b < obj.a * obj.b;
    }
};
vector<Data> arr;

struct BigInt {
    BigInt(int x) {
        num.push_back(x);
        process_digit();
    }
    BigInt(vector<int> &ret) : num(ret) {}
    BigInt operator/(int x) {
        //i 最高位, temp 余数
        int i = num.size(), temp = 0;
        while (i && temp * 10 + num[i - 1] < x) temp = temp * 10 + num[i - 1], i--;
        if (!i) return BigInt(0);
        vector<int> ret(i);
        while (i) {
            temp = temp * 10 + num[i - 1];
            ret[i - 1] = temp / x;
            temp %= x;
            i--;
        }
        return BigInt(ret);
    }
    bool operator>(const BigInt &obj) {
        if (num.size() - obj.num.size()) return num.size() > obj.num.size();
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == obj.num[i]) continue;
            return num[i] > obj.num[i];
        }
        return 1;
    }
    BigInt operator*=(const BigInt &obj) {
        
    }
    void process_digit() {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        return ;
    }
    vector<int> num;
};

ostream &operator<<(ostream &out, const BigInt &obj) {
    for (int i = obj.num.size() - 1; i >= 0; i--) {
        out << obj.num[i];
    } 
    return out;
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin() + 1, arr.end());
    BigInt p = arr[0].a, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p / arr[i].b > ans) {
            p *= arr[i].a;
        }
    }
    cout << ans << endl;
    return 0;
}

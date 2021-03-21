/*************************************************************************
	> File Name: oj-474.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月11日 星期四 14时46分10秒
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
#include <deque>
using namespace std;

struct BigFloat {
    BigFloat(int x) {
        lpart.push_back(x);
        process_digit();
    }
    void trim() {
        while (lpart.size() > 1 && lpart[0] == 0) lpart.pop_front();
        while (rpart.size() && rpart[rpart.size() - 1] == 0) rpart.pop_back();
        return;
    }
    void operator>>=(int x) {
        while (x--) {
            if (lpart.size()) {
                rpart.push_front(lpart.back());
                lpart.pop_back();
            } else {
                rpart.push_front(0);
            }
        }
        if (!lpart.size()) lpart.push_back(0);
        trim();
    }
    void process_digit() {
        for (int i = rpart.size() - 1; i >= 0; i--) {
            if (rpart[i] < 10) continue;
            if (i == 0) lpart[lpart.size() - 1] += rpart[i] / 10;
            else rpart[i - 1] += rpart[i] / 10;
            rpart[i] %= 10;
        }
        for (int i = lpart.size() - 1; i >= 0; i--) {
            if (lpart[i] < 10) continue;
            if (i == 0) lpart.push_front(0), i++;
            lpart[i - 1] += lpart[i] / 10;
            lpart[i] %= 10;
        }
        trim();
    }

    void operator*=(int x) {
        for (int i = rpart.size() - 1; i >= 0; i--) {
            rpart[i] *= x;
        }
        for (int i = lpart.size() - 1; i >= 0; i--) {
            lpart[i] *= x;
        }
        process_digit();
    }

    deque<int> lpart, rpart;
};

ostream &operator<<(ostream &out, const BigFloat &obj) {
    for (int i = 0; i < obj.lpart.size(); i++) {
        out << obj.lpart[i];
    }
    if (!obj.rpart.size()) return out;
    out << ".";
    for (int i = 0; i < obj.rpart.size(); i++) {
        out << obj.rpart[i];
    }
    return out;
}

int main() {
    int n, p[4];
    string str;
    cin >> n >> str;
    BigFloat ans = 1;
    for (int i = 0; i < n; i++) {
        char ch;
        for (int j = 0; j < 4; j++) {
            cin >> p[j] >> ch;
        }
        ans *= p[str[i] - 'A'];
        ans >>= 2;
    }
    cout << ans << endl;
    return 0;
}

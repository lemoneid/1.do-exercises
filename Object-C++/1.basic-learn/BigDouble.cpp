/*************************************************************************
	> File Name: BigDouble.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月15日 星期二 19时27分29秒
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

struct BigFloat {
    BigFloat(int x) {
        lpart.push_back(x);
        process_digit();
    }

    void operator*=(int x) {
        for (int i = 0; i < lpart.size(); ++i) lpart[i] *= x;
        for (int i = 0; i < rpart.size(); ++i) rpart[i] *= x;
        process_digit();
        return ;
    }
    void trim() {
        while (lpart.size() > 1 && lpart[0] == 0) lpart.pop_front();
        while (rpart.size() != 0 && rpart[rpart.size() - 1] == 0) rpart.pop_back();
        return ; 
    }

    void operator<<=(int x) {
        while (x--) {
            if (lpart.size()) {
                rpart.push_front(lpart[lpart.size() - 1]);
                lpart.pop_back();
            } else {
                rpart.push_front(0);
            }
        }
        if (lpart.size() == 0) lpart.push_front(0);
        trim();
        return ;
    }

    void process_digit() {
        for (int i = rpart.size() - 1; i >= 0; i--) {
            if (rpart[i] < 10) continue;
            if (i == 0) {
                lpart[lpart.size() - 1] += rpart[i] / 10;
            } else {
                rpart[i - 1] += rpart[i] / 10;
            }
            rpart[i] %= 10;
        }
        for (int i = lpart.size() - 1; i >= 0; --i) {
            if (lpart[i] < 10) continue;
            if (i == 0) lpart.push_front(0), ++i;
            lpart[i - 1] += lpart[i] / 10;
            lpart[i] %= 10;
        }
        trim();
    }
    
    deque<int> lpart, rpart;
};

ostream &operator<<(ostream &out, const BigFloat &obj) {
    for (int i = 0; i < obj.lpart.size(); ++i) out << obj.lpart[i];
    if (obj.rpart.size()  == 0) return out;
    out << '.';
    for (int i = 0; i < obj.rpart.size(); ++i) out << obj.rpart[i];
    return out;
}

int main() {
    int n, p[4];
    string str;
    cin >> n >> str;
    BigFloat ans = 1;
    for (int i = 0; i < n; ++i) {
        char ch;
        for (int j = 0; j < 4; ++j) {
            cin >> p[j] >> ch;
        }
        ans *= p[str[i] - 'A'];
        ans <<= 2;
    }
    cout << ans << endl;
    return 0;
}

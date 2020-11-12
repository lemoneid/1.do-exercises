/*************************************************************************
	> File Name: cd-47.cpp
	> Author: wei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月09日 星期一 09时42分49秒
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

bool isValid(string p) {
    if (!(p.size() & 1)) return false;
    for (int i = 0, j = 1; i < p.size(); i += 2, j += 2) {
        if (p[i] != '1' && p[i] != '0') return false;
        if (j < p.size() && p[j] != '&' && p[j] != '|' && p[j] != '^') return false;
    }
    return true;
}

int calc(string p, bool desire, int l, int r) {
    if (l == r) {
        if (p[l] == '1') {
            return desire ? 1 : 0;
        } else {
            return desire ? 0 : 1;
        }
    }
    int res = 0;
    if (desire) {
        for (int i = l + 1; i < r; i += 2) {
            switch (p[i]) {
                case '&':
                    res += calc(p, true, l, i - 1) * calc(p, true, i + 1, r);
                    break;
                case '|':
                    res += calc(p, true, l, i - 1) * calc(p, true, i + 1, r);
                    res += calc(p, true, l, i - 1) * calc(p, false, i + 1, r);
                    res += calc(p, false, l, i - 1) * calc(p, true, i + 1, r);
                    break;
                case '^':
                    res += calc(p, false, l, i - 1) * calc(p, true, i + 1, r);
                    res += calc(p, true, l, i - 1) * calc(p, false, i + 1, r);
                    break;
            }
        }
    } else {
        for (int i = l + 1; i < r; i += 2) {
            switch (p[i]) {
                case '&':
                    res += calc(p, false, l, i - 1) * calc(p, false, i + 1, r);
                    break;
                case '|':
                    res += calc(p, false, l, i - 1) * calc(p, false, i + 1, r);
                    break;
                case '^':
                    res += calc(p, false, l, i - 1) * calc(p, false, i + 1, r);
                    res += calc(p, true, l, i - 1) * calc(p, true, i + 1, r);
                    break;
            }
        }
        
    }
    return res;
}

int func(string p, bool desire) {
    if (p.size() == 0) return 0;
    if (!isValid(p)) return 0;
    return calc(p, desire, 0, p.size() - 1);
}

int main() {
    string expr;
    bool desire;
    cin >> expr >> desire;
    int ans = func(expr, desire);
    cout << ans << endl;
    return 0;
}

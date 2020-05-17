/*************************************************************************
	> File Name: EP44-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月17日 星期日 18时19分27秒
 ************************************************************************/

#include <iostream>
#include <inttypes.h>
using namespace std;

typedef long long int1;

inline int1 P(int1 n) {
    return n * (3 * n - 1) / 2;
}

int binary_search(int1 (*func)(int1), int1 l, int1 r, int1 x) {
    int head = l, tail = r, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }   
    return 0;
}


int main() {
    int1 n = 2, D = INT32_MAX;
    while (P(n) - P(n - 1) < D) {
        int1 pk = P(n);
        for (int j = n - 1; j >= 1; --j) {
            int1 pj = P(j);
            if (pk - pj > D) break;
            int flag = 1;
            flag = flag && (binary_search(P, 1, pk + pj, pk + pj));
            flag = flag && (binary_search(P, 1, pk - pj, pk - pj));    
            if (!flag) continue;
            D = pk - pj;
            cout << D << endl;
            fflush(stdout);
        }
        ++n;
    }
    cout << D << endl;
    return 0;
}

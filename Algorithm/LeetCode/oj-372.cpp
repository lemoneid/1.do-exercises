#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int MAX_N = 500000;
int a[MAX_N + 5], b[MAX_N + 5];

int main() {
    int n, t1 = 0, t2 = 0, p = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    while (p < n) {
        while (t1 != -1 && a[p] < a[t1]) t1--;
        while (t2 != -1 && b[p] < b[t2]) t2--;
        if (t1 != t2) break;
        a[++t1] = a[p];
        b[++t2] = b[p];
        p++;
    }
    cout <<p << endl;

    return 0;
}

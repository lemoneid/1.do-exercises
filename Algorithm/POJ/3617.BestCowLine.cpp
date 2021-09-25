/*************************************************************************
	> File Name: 3617.BestCowLine.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月25日 星期六 15时13分10秒
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

const int MAX_N = 2000;
char s[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int a = 0, b = n - 1, count = 0;
    while (a <= b) {
        bool left = false;
        for (int i = 0; i <= b - a; i++) {
            if (s[a + i] < s[b - i]) {
                left = true;
                count++;
                break;
            } else if (s[a + i] > s[b - i]) {
                count++;
                left = false;
                break;
            }
        }
        if (left) putchar(s[a++]);
        else putchar(s[b--]);
        if (count % 80 == 0) cout << endl;
    }
    cout << endl;
    return 0;
}

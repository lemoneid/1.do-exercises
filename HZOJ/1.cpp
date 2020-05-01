#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, l1, r1, l2, r2, num[10005] = {0};
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num + l1 - 1, num + r1);
    sort(num + l2 - 1, num + r2, cmp);
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << num[i];
    }
    return 0;
}

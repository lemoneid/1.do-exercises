#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 1000

int Sub(int *p1, int len1, int *p2, int len2) {
    if (len1 < len2) return -1;
    if (len1 == len2) {
        for (int i = len1 -1; i >= 0; --i) {
            if (p1[i] == p2[i]) continue;
            if (p1[i] > p2[i]) {
                break;
            } else {
                return -1;
            }
        }
    }
    for (int i = 0; i <= len1 - 1; i++) {
        p1[i] -= p2[i];
        if (p1[i] < 0) {
            --p1[i + 1];
            p1[i] += 10;
        }
    }
    for (int i = len1 - 1; i >= 0; --i) {
        if (p1[i]) {
            return (i + 1);
        }
    }
    return 0;
}

int Div(char *num1, char *num2, int *ans) {

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int dValue, tmp, len = 0;
    int num_a[SIZE + 5] = {0};
    int num_b[SIZE + 5] = {0};
    
    for (int i = 0, j = len1 - 1; j >= 0; ++i, --j) num_a[i] = num1[j] - '0';
    for (int i = 0, j = len2 - 1; j >= 0; ++i, --j) num_b[i] = num2[j] - '0';

    if (len1 < len2) {
        return 0;
    }
    
    dValue = len1 - len2;
    for (int i = len1 - 1; i >= 0; --i) {
        if (i >= dValue) num_b[i] = num_b[i - dValue];
        else num_b[i] = 0;
    }
    
    len2 = len1;
    for (int i = 0; i <= dValue; ++i) {
        while ((tmp = Sub(num_a, len1, num_b + i, len2 - i)) >= 0) {
            len1 = tmp;
            ans[dValue - i] += 1;
        }
    }

    int id = dValue;
    while (id) {
        if (ans[id]) break;
        id--;
    }
    len = id + 1;
    return len;
}

int main() {
    char num1[SIZE + 5] = {0}, num2[SIZE + 5] = {0};
    int ans[SIZE + 5] = {0};
    cin >> num2 >> num1;
    // num2 / num1
    int len = Div(num1, num2, ans);
    for (int i = len - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;
}

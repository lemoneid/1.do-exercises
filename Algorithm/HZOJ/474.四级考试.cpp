/*************************************************************************
	> File Name: 474.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Fri 28 Aug 2020 06:19:03 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n;
int ans[250] = {1, 1};
char src[105];

int mul(char *a) {
    if (a[0] == '0') {
        return -1;
    }
    if (strlen(a) == 4) {
        for (int i = ans[0]; i > 0; --i) {
            ans[i + 2] = ans[i];
        } 
        ans[1] = ans[2] = 0;
        ans[0] += 2;
        return 0;
    }
    
    int tmp[10] = {0};
    tmp[0] = strlen(a) - 1;
    for (int i = 1, j = tmp[0] - 1; i <= tmp[0]; i++, j--) {
        tmp[i] = a[j] - '0';
    }
    int product[250] = {max(ans[0], tmp[0])};
    for (int i = 1; i <= ans[0]; ++i) {
        for (int j = 1; j <= tmp[0]; ++j) {
            product[i + j - 1] += ans[i] * tmp[j];
        }
    }

    for (int i = 1; i <= product[0]; ++i) {
        product[i + 1] += product[i] / 10;
        product[i] %= 10;
    }
    
    for (int i = product[0] + 1; product[i]; ++i) {
        product[0] = i;
        product[i + 1] += product[i] / 10;
        product[i] %= 10;
    }
    for (int i = product[0]; i > 0; i--) {
        ans[i] = product[i];
    }
    ans[0] = product[0];
    return 0;

}

int main() {
    cin >> n >> src;
    for (int i = 0; i < n; ++i) {
        char a[5], b[5], c[5], d[5];
        int flag = 0;
        cin >> a >> b >> c >> d;
        switch (src[i]) {
            case 'A' : flag = mul(a); break;
            case 'B' : flag = mul(b); break;
            case 'C' : flag = mul(c); break;
            case 'D' : flag = mul(d); break;
        }
        if (flag == -1) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (ans[n * 2 + 1]) {
        cout << 1 << endl;
        return 0;
    }

    char res[250] = {0};
    for (int i = n * 2, j = 0; i > 0; i--, j++) {
        res[j] = ans[i] + '0';
    }
    for (int i = strlen(res) - 1; i > 0; i--) {
        if (res[i] != '0') break;
        res[i] = 0;
    }

    cout << "0." << res << endl;
    return 0;
}

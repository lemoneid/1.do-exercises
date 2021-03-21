/*************************************************************************
	> File Name: oj-234.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月15日 星期一 11时11分04秒
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

int arr[15][5];
int check[15];

int main() {
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 4; j++) {
            char ch;
            cin >> ch;
            if (ch > '1' && ch <= '9') {
                arr[i][j] = ch - '0';
                continue;
            } 
            switch (ch) {
                case '0' : arr[i][j] = 10; break;
                case 'A' : arr[i][j] = 1; break;
                case 'J' : arr[i][j] = 11; break;
                case 'Q' : arr[i][j] = 12; break;
                case 'K' : arr[i][j] = 13; break;
                default : break;
            }
        }
        arr[i][0] = 4;
    }

    int life = 4; 
    int x = arr[13][1];
    arr[13][0]--;
    while (life) {
        check[x]++;
        if (x == 13) {
            life--;
            if (!life) break;
            x = arr[x][5 - arr[x][0]--];
        } else {
            x = arr[x][arr[x][0]--];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 12; i++) {
        if (check[i] == 4) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

/*************************************************************************
	> File Name: EP11.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月16日 星期六 18时05分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[25][25] = {0};

int H(int i, int j) {
    if (j + 3 >= 20) return 0;
    int temp = 1;
    for (int k = 0; k < 4; ++k) 
        temp *= arr[i][j + k];
    return temp;
}

int S(int i, int j) {
    if (i + 3 >= 20) return 0;
    int temp = 1;
    for (int k = 0; k < 4; ++k) 
        temp *= arr[i + k][j];
    return temp;
}

int X(int i, int j) {
    int temp1 = 1, temp2 = 1;
    if (i + 3 < 20 && j + 3 < 20) {
        for (int k = 0; k < 4; ++k) 
            temp1 *= arr[i + k][j + k];
    }
    if (i + 3 < 20 && j - 3 >= 0) {
        for (int k = 0; k < 4; ++k) 
            temp2 *= arr[i + k][j - k];

    }
    return (temp1 > temp2 ? temp1 : temp2 );
}

int main() {
    long long sum = 0;
    for (int i = 0; i < 20; ++i) { 
        for (int j = 0; j < 20; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 20; ++i) { 
        for (int j = 0; j < 20; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int i, j;
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 20; ++j) {
            if (H(i, j) > sum) sum = H(i, j);
            if (S(i, j) > sum) sum = S(i, j);
            if (X(i, j) > sum) sum = X(i, j);
        }
    }
    printf("%lld\n", sum);
}

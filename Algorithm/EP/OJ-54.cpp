/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月23日 星期六 16时18分47秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
#define max_n 100000

int ans[max_n + 5];
int sum[max_n + 5] = {1};

void adjust(int *arr) {
    for (int j = 1; j <= arr[0]; ++j) {
        if (arr[j] < 10) continue;
            arr[j + 1] += arr[j] / 10;
            arr[j] %= 10;
            arr[0] += (j == arr[0]);
    }
    return ;
}

void output(int *arr) {
    for (int i = arr[0]; i > 0; i--){
        cout << arr[i];
    }
    cout << endl;
}
void init(int *arr) {
    arr[0] = arr[1] = 1;
    for (int i = 2; i < max_n + 5; i++) arr[i] = 0;
}

int main() {    
    int x;
    while (scanf("%d", &x) != EOF) {
        init(sum);
        init(ans);
        for (int i = 2; i <= x; ++i) {
            for (int j = 1; j <= ans[0]; ++j) {
                ans[j] *= i;
            }
            adjust(ans);
        }
        for (int i = ans[0]; i > 0; --i) {
            if (ans[i] == 0) continue;
            for (int j = 1; j <= sum[0]; ++j) {
                sum[j] *= ans[i];
            }
            adjust(sum);
        } 
        output(sum);
    }
    return 0;
}

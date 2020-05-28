/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月24日 星期日 19时57分59秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
#define max_n 100

typedef struct {
    char str[max_n] = {0}; 
} Name;
Name arr[5];
char tmp[max_n + 5];

void output(Name *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i].str << endl;
    }
    return ;
}

void solve(Name *arr, int n) {
    for (int i  = 0; i < n; ++i) {
        scanf("%s", arr[i].str);
        memset(tmp, 0, sizeof(tmp));
        int k = 0;
        //cout << i << " = " << arr[i].str;
        for (int j = 0; arr[i].str[j];) {
            if (strncmp((arr[i].str)+ j, "Ban_smoking", 11)) {
                tmp[k++] = arr[i].str[j++];
                continue;
            }
            //cout << arr[i].str << endl;
            strncpy(tmp + k, "No_smoking", 10);
            k += 10;
            j += 11;
        }
        tmp[k] = '\0';
         cout << endl <<i << " sizof : " << sizeof(tmp) << " strlen ;" << strlen(tmp) << endl;
        strncpy(arr[i].str, tmp, sizeof(tmp));
    }
    output(arr, n);
    return ;
}


int main() {
    int n;
    cin >> n;
    solve(arr, n);
    return 0;
}

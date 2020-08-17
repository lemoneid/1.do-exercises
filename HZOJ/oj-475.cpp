/*************************************************************************
	> File Name: oj-475.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com 
	> Created Time: Sat 15 Aug 2020 02:32:44 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 1005


int ans_len;

int check(char *mod, char *num1) {
    int len1 = strlen(mod) - 1;
    int len2 = strlen(num1);
    if (len1 > len2) {
        return 1;
    } else if(len1 < len2) {
        return 0;
    }
    for (int i = ans_len, j = 0; j < len1; i--, j++ ) {
        if (mod[i] == num1[j]) continue;
        return mod[i] > num1[j];
    }
    return 1;
}

int main() {
    char num1[SIZE] = {0}, num2[SIZE] = {0}, mod[SIZE] = {'0'};
    int ans[SIZE] = {0};
    int id = 0;
    cin >> num1 >> num2;

    for (int i = 0; i < strlen(num2); ++i) {
        for (int j = ans_len; j > 0; --j) {
            mod[j + 1] = mod[j];
        }
        ans_len++;
        mod[1] = num2[i];
        
        //mod-length
        int cnt = 1;
        for (int j = ans_len; j > 0; --j) {
            if (mod[j] != '0') {
                cnt = j;
                break;
            }
        }

        ans_len = cnt;

        while(check(mod, num1)) {
            for (int i = 1, j = strlen(num1) -1; j >= 0; i++, j--) {
                mod[i] = mod[i] - num1[j] + '0';
            }
            for (int i = 1; i <= ans_len; ++i) {
                if (mod[i] < '0') {
                    mod[i + 1]--;
                    mod[i] += 10;
                }
            }
            int cnt2 = 0;
            for (int i = 1; i <= ans_len; ++i) {
                if (mod[i] != '0') {
                    cnt2 = i;
                }
            }
            ans_len = cnt2;
            for (int i = cnt2 + 1; i < SIZE; ++i) {
                if (mod[i] == 0) break;
                mod[i] = 0;
            }
            ans[id]++;
        }
        id++;
    }

    int flag = 0;
    for (int i = 0; i < id; ++i) {
        if (flag == 0 && ans[i] == 0) continue;
        flag = 1;
        cout << ans[i];
    }
    if (!flag) cout << 0;
    cout << endl;
    return 0;
}

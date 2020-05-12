/*************************************************************************
	> File Name: 1.杨辉三角.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月10日 星期日 16时54分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
const int SIZE = 1000;
int prime[SIZE] = {0}, check[SIZE] = {0};
void init() {
    int pos = 0;
    for (int i = 2; i * i < SIZE; ++i) {
        if (!check[i]) prime[pos++] = i;
        for (int j = 0; i * prime[j] < SIZE && j < pos; ++j){
            check[i * prime[j]] = 1;
            if(!(i % prime[j])) break;
        }
    }
}

int main() {
    init();
    for (int i = 0; i < 10; i++) {
        cout << prime[i] << " ";
    }
    cout << endl;
    return 0;
}

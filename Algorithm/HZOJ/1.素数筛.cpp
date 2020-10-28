/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月03日 星期日 20时33分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

const int SIZE = 10000005;

int prime[SIZE] = {0}, check[SIZE] = {0};
int p_num = 0;

void init() {
    for (int i = 2; i < SIZE; i++){
        check[i] || (prime[p_num++] = i);
        for(int j = 0; j < p_num && i * prime[j] < SIZE; j++){
            check[i * prime[j]] = 1;
            if(!(i % prime[j]))
                break;
        }
    }
    return ;
}

int main() {
    int a, b, i = 0;
    cin >> a >> b;
    init();
    while(prime[i] < a) 
        i++;
    while(prime[i] <= b && prime[i]){
        cout << prime[i++] << endl;
    }
    return 0;
}

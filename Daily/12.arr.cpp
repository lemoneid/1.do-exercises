/*************************************************************************
	> File Name: 12.arr.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月10日 星期日 20时10分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int arr[2][3][4] = {0, 1, 3 ,4};
    int *p;
    printf("arr[%d] = %p\n", 0, arr);
    cout << sizeof(int) << endl;
    printf("arr[%d] = %p\n", 1, &arr[1]);
    printf("arr[%d] = %p\n", 11, &arr[1][1]);
    printf("arr[%d] = %p\n", 12, &arr[1][2]);
    printf("arr[%d] = %p\n", 121, &arr[1][2][1]);
    printf("%d", sizeof(p));
    return 0;
}

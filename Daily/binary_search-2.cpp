/*************************************************************************
	> File Name: binary_search-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月19日 星期二 20时59分07秒
 ************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;

int binary_search(int *arr, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        cout << "head: " << head << " tail: " << tail << endl;
        mid = (head + tail) >> 1;
        if (arr[mid] == 1) tail = mid;
        //if (arr[mid - 1] == 1) tail = mid - 1;
        else head = mid + 1;
    }
    return head != n ? tail : -1;
}

int main() {
    //int arr[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    int arr[10] = {0};
    int n;
    while (cin >> n){
        memset(arr, 0, sizeof(arr));
        for (int i = n; i < 10; ++i)
            arr[i] = 1;
        for (int i = 0; i < 10; ++i) {
            cout << arr[i] <<" ";
        }
        cout << endl;
        for (int i = 0; i < 10; ++i) {
            cout << i <<" ";
        }
        cout << endl;
        cout << binary_search(arr, 10) << endl;

    }

    return 0;
}

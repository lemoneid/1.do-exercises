/*************************************************************************
	> File Name: binary_search-1.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月19日 星期二 20时59分07秒
 ************************************************************************/

#include <iostream>
using namespace std;


int binary_search(int *arr, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        cout << "head: " << head << " tail" << tail << endl;
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == 1) head = mid;
        //if (arr[mid + 1] == 1) head = mid + 1;
        else tail = mid - 1;
    }
    cout << head << endl;;
    return head == 1;
}

int main() {
    int arr[10] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
    cout << binary_search(arr, 9) << endl;
    return 0;
}

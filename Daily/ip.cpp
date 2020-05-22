/*************************************************************************
	> File Name: ip.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年05月19日 星期二 19时18分09秒
 ************************************************************************/

#include <iostream>
using namespace std;

union IP {
    struct {
     unsigned char a1;   
     unsigned char a2;   
     unsigned char a3;   
     unsigned char a4;   
    } ip;
    unsigned int num;
};

int is_little() {
    static int num = 1;
    return ((char *)&num)[0];
}

int main() {
    cout << is_little() << endl;
    union IP p;
    char str[100];
    int arr[4];
    while (~scanf("%s", str)) {
        sscanf(str,"%d.%d.%d.%d", arr, arr + 1, arr + 2, arr + 3);
        p.ip.a1 = arr[3];
        p.ip.a2 = arr[2];
        p.ip.a3 = arr[1];
        p.ip.a4 = arr[0];
        printf("%p\n", &p.ip.a1);
        printf("%p\n", &p.ip.a2);
        printf("%p\n", &p.ip.a3);
        printf("%p\n", &p.ip.a4);
        printf("%p\n", &p.num);
        cout << p.num << endl;
    }
    return 0;
}

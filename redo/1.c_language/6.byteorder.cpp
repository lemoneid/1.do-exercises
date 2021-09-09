/*************************************************************************
	> File Name: 6.byteorder.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月08日 星期三 17时11分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
union {
    short value;
    char union_bytes[sizeof(short)];
} byteOrder;

int main() {
    byteOrder.value = 0x0102;
    for (int i = 0; i < sizeof(short); i++) {
        cout << (int)byteOrder.union_bytes[i] << endl;
    }
    if((byteOrder.union_bytes[0]==1) && (byteOrder.union_bytes[1]==2))
    {
        printf("big endian\n");
    }
    else if((byteOrder.union_bytes[0]==2) && (byteOrder.union_bytes[1]==1))
    {
        printf("little endian\n");
    }
    else
    {
        printf("unknown...\n");
    }
    return 0;
}

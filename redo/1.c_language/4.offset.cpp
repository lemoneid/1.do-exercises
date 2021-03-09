/*************************************************************************
	> File Name: 4.offset.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月08日 星期一 21时07分09秒
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

#define offset(T, a) (long(&(((T*)(NULL))->a)))

/*
#define offset(T, a) ({\
    T temp;\
    (char *)(&temp.a) - (char *)(&temp);\
})
*/

struct Data {
    char a;
    double b;
    int c;
};

int main() {
    printf("%ld\n",offset(struct Data, a));
    printf("%ld\n",offset(struct Data, b));
    printf("%ld\n",offset(struct Data, c));
    return 0;
}

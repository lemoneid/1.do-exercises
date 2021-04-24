/*************************************************************************
	> File Name: ptr.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月21日 星期三 11时52分00秒
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

class ptrMem {
public :
    ptrMem() : data(new int[0]) {
        cout << "constructor" << endl;
    }
//    ptrMem(const ptrMem &obj) : data(new int(*(obj.data))) {
//        cout << "copy constructor" << endl;
//    }
    ~ptrMem() {
        delete data;
        cout << "destructor" << endl;
    }
public:
    int *data;
};

int main() {
    ptrMem a;
    ptrMem b(a);
    printf("%p : %d\n", a.data, *a.data);
    printf("%p : %d\n", b.data, *b.data);
    return 0;
}

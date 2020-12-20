/*************************************************************************
	> File Name: test-virtual.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月17日 星期四 10时55分57秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class Aniaml {
public : 

};

void output_raw_data(void *q, int size) {
    unsigned char *p = (unsigned char *)q;
    for (int i = 0; i < size; ++i) {
        printf("%02X ", p[i]);
    }
    cout.put(cout.widen('\n'));
    cout.flush();
    return ;
}

int main() {
    cout << sizeof(Aniaml) << endl;
    output_raw_data(new Aniaml, sizeof(Aniaml));

    return 0;
}

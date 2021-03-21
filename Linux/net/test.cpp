/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月20日 星期六 20时45分18秒
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
class Data {
public :
    Data()  {
    }
    static int a;
};

int Data::a(10);

int main() {
    cout << Data::a << endl;
    double *arr = (double *)malloc(sizeof(double) * 1000000010000);
    if (arr == NULL) cout << "null" << endl;
    return 0;
}

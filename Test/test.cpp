/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月09日 星期三 12时11分43秒
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
struct free_throws {
    int val;
    free_throws(const free_throws &a) {
        this->val = a.val;
    }
};
free_throws& clone(free_throws &ft) {
	free_throws *pt;
    *pt = ft;
    cout << "test" << endl;
    cout << pt->val << endl;
    return *pt;
}
int main() {
    free_throws three;
    three.val = 1;
    free_throws &test = clone(three);
    cout << three.val << endl;
    return 0;
}

/*************************************************************************
	> File Name: 23.try_catch.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月20日 星期二 09时23分13秒
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


class helper : public std::exception {
public :
    helper() = default;
    helper(const helper &obj) = default;
    ~helper() = default;
    const char *what() const {
        return "throw helper class";
    }
};

void inner () {
    try {
        throw(helper());
    }
    catch(const helper & e) {
        cout << e.what() << endl;
    }
    catch(std::exception &e) {
        cout << "test" << endl;
        cout << e.what() << endl;
    }
}

int main() {
     
    inner();

    return 0;
}

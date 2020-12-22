/*************************************************************************
	> File Name: singtelon.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 10时09分52秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <mutex>
using namespace std;

class Base final {
public :
    static Base *getInstance() {
        if (instance == nullptr) {
            std::unique_lock<std::mutex> lock(m_mutex);
            if (instance == nullptr) {
                instance = new Base();
            }
        }
        return instance;
    }

private :
    Base() {}
    Base(const Base &) = delete;
    ~Base() {}
    static Base *instance;
    static std::mutex m_mutex;
};

//Base *Base::instance = new Base();
Base *Base::instance = nullptr;
std::mutex Base::m_mutex;


int main() {
    Base *t1 = Base::getInstance();
    Base *t2 = Base::getInstance();
    cout << t1 << " " << t2 << endl;

    return 0;
}

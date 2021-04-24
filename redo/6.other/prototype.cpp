/*************************************************************************
	> File Name: prototype.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月23日 星期五 16时43分35秒
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
#include <memory>
#include <mutex>

class singleton {
public : 
    static singleton *getInstance() {
        if (instance == nullptr) {
            std::unique_lock<std::mutex> lock(m_mutex);
            if (instance == nullptr) {
                instance = new singleton;
            }
        }
        return instance;
    }
private :
    singleton() = default;
    ~singleton() = default;
    singleton(const singleton &) = default;
    static singleton *instance;
    static std::mutex m_mutex;
};
singleton *singleton::instance = nullptr;
std::mutex singleton::m_mutex;


int main() {
    singleton *t1 = singleton::getInstance();
    singleton *t2 = singleton::getInstance();
    std::cout << t1 << " " << t2;
    return 0;
}

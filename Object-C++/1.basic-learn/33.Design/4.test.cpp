/*************************************************************************
	> File Name: 3.singleton.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月20日 星期日 10时39分18秒
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

class Singleton {
public :
    static Singleton *getInstance() {
        //多线程有内存泄漏,加锁
        //双重验证,可以允许读,解决效率问题
        if (instance == nullptr) { //防止无意义的重复加锁
            std::unique_lock<std::mutex> lock(m_mutex);
            if (instance == nullptr) { //防止内存泄露
                instance = new Singleton();
            } 
        }
        return instance;
    }

private :
    static Singleton *instance;
    static std::mutex m_mutex;
    Singleton() {}
    Singleton(const Singleton &) = delete;
    ~Singleton() {}
};

//Singleton *Singleton::instance = new Singleton(); //恶汉模式,直接初始化
Singleton *Singleton::instance = nullptr; //懒汉模式,加锁,判断,需要时在初始化
std::mutex Singleton::m_mutex;

int main() {
    /*
    Singleton h1;
    Singleton h2(h1);
    Singleton h3 = h1;
    */
    Singleton *t1 = Singleton::getInstance();
    Singleton *t2 = Singleton::getInstance();
    cout << t1 << " " << t2 << endl;
    return 0;
}

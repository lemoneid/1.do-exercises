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

class HttpServer {
public :
    static HttpServer *getInstance() {
        //多线程有内存泄漏,加锁
        //双重验证,可以允许读,解决效率问题
        if (instance == nullptr) { //防止无意义的重复加锁
            std::unique_lock<std::mutex> lock(m_mutex);
            if (instance == nullptr) { //防止内存泄露
                instance = new HttpServer();
            } 
        }
        return instance;
    }

private :
    static HttpServer *instance;
    static std::mutex m_mutex;
    HttpServer() {}
    HttpServer(const HttpServer &) = delete;
    ~HttpServer() {}
};

//HttpServer *HttpServer::instance = new HttpServer(); //恶汉模式,直接初始化
HttpServer *HttpServer::instance = nullptr; //懒汉模式,加锁,判断,需要时在初始化
std::mutex HttpServer::m_mutex;

int main() {
    /*
    HttpServer h1;
    HttpServer h2(h1);
    HttpServer h3 = h1;
    */
    HttpServer *t1 = HttpServer::getInstance();
    HttpServer *t2 = HttpServer::getInstance();
    cout << t1 << " " << t2 << endl;
    return 0;
}

/*************************************************************************
	> File Name: 16.priority_queue.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月16日 星期五 21时28分27秒
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
 
class IQueue {
public :
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual int size() = 0;
};

class vector_queue : public IQueue, public vector<int> {
public : 
    void push(int x) override {
        this->vector<int>::push_back(x);
        return ;
    }
    void pop() override {
        if (empty()) return ;
        vector<int>::iterator p = this->begin();
        for (auto iter = begin(); iter != end(); iter++) {
            if (*iter > *p) p = iter;
        }
        erase(p);
        return ;
    }
    bool empty() override {
        return size() == 0;
    }
    int top() override {
        if (empty()) {
            throw std::exception();
        }
        int ans = at(0);
        for (int i = 1; i < size(); i++) {
            ans = max(ans, at(i));
        }
        return ans;
    }
    int size() override {
        return this->std::vector<int>::size();
    }
};

class heap_queue : public IQueue, public vector<int> {
public : 
    void push(int x) override {
        push_back(x);
        up_maintain(size());
        return ;
    }
    void pop() override {
        if (empty()) return ;
        std::swap(at(0), at(size() - 1));
        this->std::vector<int>::pop_back();
        down_maintain(0);
        return ;
    }
    bool empty() override {
        return size() == 0;
    }
    int top() override {
        if (empty()) {
            return -1;
        }
        return at(0);
    }
    int size() override {
        return this->std::vector<int>::size();
    }
private :
    void up_maintain(int ind) {
        while (ind > 1 && at(ind - 1) > at(ind / 2 - 1)) {
            std::swap(at(ind - 1), at(ind / 2 - 1));
            ind /= 2;
        }
        return ; 
    }
    void down_maintain(int ind) {
        int total = size() - 1;
        while (ind * 2 <= total) {
            int child = ind * 2;
            if (child + 1 <= total && at(child) < at(child + 1)) child++;
            if (at(child) < at(ind)) break;
            std::swap(at(child), at(ind));
            ind = child;
        }
        return ;
    }
};

int main() {
    srand(time(0));
    vector_queue q1;
    heap_queue q2;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        q1.push(val);
        cout  << "push q1 : " << val << endl;
    }
    while (!q1.empty()) {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        q2.push(val);
        cout  << "push q2 : " << val << endl;
    }
    for (auto cur = q2.begin(); cur != q2.end(); cur++) {
        cout << *cur << " ";
    }
    cout << endl;
    while (!q2.empty()) {
        cout << q2.top() << " " << endl;
        q2.pop();
    }
    return 0;
}

/*************************************************************************
	> File Name: factory.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月21日 星期一 10时20分29秒
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
using namespace std;

class Car {
public :
    class Factory {
    public :
        virtual Car *create() = 0;
    };

    class Handle {
    public :
        Handle() : next(nullptr) {}
        virtual bool is_valid(int) = 0;
        virtual Car *do_it() = 0;
        Handle *next;
    };

    virtual void run() = 0;
    virtual ~Car() {};
protected :
    Car() {};
};

class BmwCar : public Car {
public :
    class Factory : public Car::Factory, public Car::Handle {
    public :
        virtual Car *create() override {
            return new BmwCar();
        }
        virtual bool is_valid(int x) override {
            return x == 0;
        }
        virtual Car *do_it() override {
            return this->create();
        }

    };
    ~BmwCar() {
        cout << "BmwCar is stop" << endl;
    }
    void run() override {
        cout << "BmwCar is running" << endl;
    }
private :
    BmwCar() {}
};
class AudiCar : public Car {
public :
    class Factory : public Car::Factory, public Car::Handle {
    public :
        virtual Car *create() override {
            return new AudiCar();
        }
        virtual bool is_valid(int x) override {
            return x == 1;
        }
        virtual Car *do_it() override {
            return this->create();
        }
    };
    ~AudiCar() {
        cout << "AudiCar is stop" << endl;
    }
    void run() override {
        cout << "AudiCar is running" << endl;
    }
private :
    AudiCar() {}
};
class BenzCar : public Car {
public :
    class Factory : public Car::Factory, public Car::Handle {
    public :
        virtual Car *create() override {
            return new BenzCar();
        }
        virtual bool is_valid(int x) override {
            return x == 2;
        }
        virtual Car *do_it() override {
            return this->create();
        }
    };
    void run() override {
        cout << "BenzCar is running" << endl;
    }
    ~BenzCar() {
        cout << "BenzCar is stop" << endl;
    }
private :
    BenzCar() {}
};

class ChainMaster {
public :
    static Car::Handle *getInstance() {
        if (head == nullptr) {
            buildChain();
        } 
        return head;
    }
private :
    static Car::Handle *head;
    static void buildChain() {
        head = new BmwCar::Factory();
        head->next = new AudiCar::Factory();
        head->next->next = new BenzCar::Factory();
        head->next->next->next = nullptr;
        return ;
    }
};

Car::Handle* ChainMaster::head(nullptr);

Car::Factory *fac[3] = {new BenzCar::Factory(), new BmwCar::Factory(), new AudiCar::Factory()};

int main() {
    srand(time(0));
    Car *cars[10];
    for (int i = 0; i < 10; ++i) {
        int req = rand() % 3;
        for (auto p = ChainMaster::getInstance(); p != nullptr; p = p->next) {
            if (p->is_valid(req)) {
                cars[i] = p->do_it();
                break;
                if (cars[i] != nullptr) {
                    cout << i << endl;
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        cars[i]->run();
    }
    for (int i = 0; i < 10; ++i) {
        delete cars[i];
    }
    return 0;
}

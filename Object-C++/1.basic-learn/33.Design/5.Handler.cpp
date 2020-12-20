/*************************************************************************
	> File Name: 4.Factory.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> create Time: 2020年12月20日 星期日 11时24分35秒
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

//交给工厂,能且只能有工厂创建对象
class ICar {
public :
    class IFactory {
    public :
        virtual ICar *create() = 0;    
    };
    class IHandler {
    public :
        IHandler() : next(nullptr) {}
        virtual bool is_valid(int) = 0;
        virtual ICar *do_it() = 0;
        IHandler *next;
    };
    virtual void runc() = 0;
protected :
    ICar() {}
    ~ICar() {}
};


class BenzCar : public ICar {
    BenzCar() {}
public :
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public :
        virtual ICar *create() override {
            return new BenzCar();
        }
        virtual bool is_valid(int x) override {
            return x == 0;
        }
        virtual ICar *do_it() override {
            return this->create();
        }
    };
    virtual void runc() override {
        cout << "BenzCar run" << endl;
    }
};
class BmwCar : public ICar {
    BmwCar() {}
public:
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public :
        virtual ICar *create() override {
            return new BmwCar();
        }
        virtual bool is_valid(int x) override{
            return x == 1;
        }
        virtual ICar *do_it() override {
            return this->create();
        }
    };
    virtual void runc() override {
        cout << "BmwCar run" << endl;
    }
};
class AudiCar : public ICar {
    AudiCar() {}
public :
    class Factory : public ICar::IFactory, public ICar::IHandler {
    public :
        virtual ICar *create() override {
            return new AudiCar();
        }
        virtual bool is_valid(int x) override {
            return x == 2;
        }
        virtual ICar *do_it() override {
            return this->create();
        }
    };
    virtual void runc() override {
        cout << "AudiCar run" << endl;
    }
};

class ChainMaster {
public :
    static ICar::IHandler *getInstance() {
        if (head == nullptr) {
            buildChain();
        }
        return head;
    }
private :
    static ICar::IHandler *head;
    static void buildChain() {
        head = new BmwCar::Factory(); 
        head->next = new AudiCar::Factory();
        head->next->next = new BenzCar::Factory();
        return ;
    }
};
ICar::IHandler* ChainMaster::head = nullptr;

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; ++i) {
        int request = rand() % 3;
        for (auto p  = ChainMaster::getInstance(); p; p = p->next) {
            if (p->is_valid(request)) {
                cars[i] = p->do_it();
                break;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        cars[i]->runc();
    }
    return 0;
}

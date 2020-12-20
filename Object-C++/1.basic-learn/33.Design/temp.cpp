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
    virtual void runc() = 0;
protected :
    ICar() {}
    ~ICar() {}
};


class BenzCar : public ICar {
    BenzCar() {}
public :
    class Factory : public ICar::IFactory {
    public :
        virtual ICar *create() {
            return new BenzCar();
        }
    };
    virtual void runc() {
        cout << "BenzCar run" << endl;
    }
};
class BmwCar : public ICar {
    BmwCar() {}
public:
    class Factory : public ICar::IFactory {
    public :
        virtual ICar *create() {
            return new BmwCar();
        }
    };
    virtual void runc() {
        cout << "BmwCar run" << endl;
    }
};
class AudiCar : public ICar {
    AudiCar() {}
public :
    class Factory : public ICar::IFactory {
    public :
        virtual ICar *create() {
            return new AudiCar();
        }
    };
    virtual void runc() {
        cout << "AudiCar run" << endl;
    }
};

ICar::IFactory *fac[3] = {new BenzCar::Factory(), new BmwCar::Factory(), new BmwCar::Factory()};

int main() {
    srand(time(0));
    ICar *cars[10];
    for (int i = 0; i < 10; ++i) {
        cars[i] = fac[rand() % 3]->create();
    }
    for (int i = 0; i < 10; ++i) {
        cars[i]->runc();
    }
    return 0;
}

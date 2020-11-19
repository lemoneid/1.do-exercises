/*************************************************************************
	> File Name: cd-100.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月15日 星期日 10时12分55秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<int, int> PII;

class Animal {
    public :
    Animal(){id = 0;}
    void add(int type, int num) {
        if (type == 1) {
            cat.push(PII(id++, num));
        } else {
            dog.push(PII(id++, num));
        }
    }
    void pollAll() {
        while (!cat.empty() || !dog.empty())  {
            if (cat.empty() || (!dog.empty() && dog.front().first < cat.front().first)) {
                cout << "dog " << dog.front().second << endl;
                dog.pop();
            } else {
                cout << "cat " << cat.front().second << endl;
                cat.pop();
            }
        }
    }
    
    void pollDog() {
        while (!dog.empty()) {
            cout << "dog " << dog.front().second << endl;
            dog.pop();
        }
    }
    void pollCat() {
        while (!cat.empty()) {
            cout << "cat " << cat.front().second << endl;
            cat.pop();
        }
    }
    void isEmpty() {
        if (dog.empty() && cat.empty()){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    void isDogEmpty() {
        if (dog.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    void isCatEmpty() {
        if (cat.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    private :
        queue<pair<int, int>> dog;
        queue<pair<int, int>> cat;
        int id;
};

Animal res;
int n, num;
string op, type;
unordered_map<string, int> mmap;

void init() {
    mmap["add"] = 1;
    mmap["pollAll"] = 2;
    mmap["isEmpty"] = 3;
    mmap["isDogEmpty"] = 4;
    mmap["isCatEmpty"] = 5;
    mmap["pollDog"] = 6;
    mmap["pollCat"] = 7;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op;
        switch (mmap[op]) {
            case 1:
                cin >> type >> num;
                res.add(type == "cat", num);
                break;
            case 2:
                res.pollAll();
                break;
            case 3:
                res.isEmpty();
                break;
            case 4:
                res.isDogEmpty();
                break;
            case 5:
                res.isCatEmpty();
                break;
            case 6:
                res.pollDog();
                break;
            case 7:
                res.pollCat();
                break;
        }
    }
    return 0;
}

/*************************************************************************
	> File Name: 28.auto.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月19日 星期六 15时27分36秒
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
#include <ctime>
using namespace std;

string randString() {
    string ret = "";
    for (int i = 0; i < rand() % 8 + 1; ++i) {
        ret += rand() % 26 + 'A';
    }
    return ret;
}

int my_seed = 1;
void my_rand(int seed) {
    my_seed = seed;
}

int my_ind() {
   my_seed = my_seed * 3 % 101; 
    return my_seed;
}


int main() {
    my_rand(time(0));
    for (int i = 0; i <= 120; ++i) {
        cout << my_ind() << " ";
        if (i % 10 == 0) cout << endl;
    }
    cout << "---------------" << endl;
    long long a = 123;
    auto b = 123L;
    srand(14);
    cout << typeid(int).name() << endl;
    cout << sizeof(a) << " " << typeid(a).name() << endl;
    cout << sizeof(b) << " " << typeid(b).name() << endl;
    cout << "--------------------" << endl;
    map<string, int> ind;
    for (int i = 0; i < 5; ++i) {
        ind[randString()] = rand() % 100;
    }
    //map<string, int>::iterator iter;
    auto iter = ind.begin();
    for (;iter != ind.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    for (auto x : ind) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

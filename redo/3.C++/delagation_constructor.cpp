/*************************************************************************
	> File Name: delagation_constructor.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月21日 星期三 21时55分23秒
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
#include <list>
#include <queue>
using namespace std;

class TDConstructed {
public :
    TDConstructed(vector<short> &v) : TDConstructed(v.begin(), v.end()) {}
    TDConstructed(deque<int> &d) :TDConstructed(d.begin(), d.end()) {}
private :
    template<typename T> 
    TDConstructed(T first, T last) : l(first, last) {}
    list<int> l;
};


int main() {

    return 0;
}

/*************************************************************************
	> File Name: 22.用栈来求解汉诺塔问题.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年09月27日 星期日 21时13分23秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define print(x, a, b) cout << "Move " << x << " from " << a << " to " << b << endl;

int num;

int move(int num, string from, string to) {
    if (num == 1) {
        if (from == "mid" || to == "mid") {
            print(num, from, to);
            return 1;
        } else {
            print(num, from, "mid");
            print(num, "mid", to);
            return 2;
        }
    }
    if (from == "mid" || to == "mid") {
        string another = (from == "left" || to == "left") ? "right" : "left";
        int part1 = move(num - 1, from, another);
        int part2 = 1;
        print(num, from, another);
        int part3 = move(num - 1, another, to);
        return part1 + part2 + part3;
    } else {
        int part1 = move(num - 1, from, to);
        int part2 = 1;
        print(num, from, "mid");
        int part3 = move(num - 1, to, from);
        int part4 = 1;
        print(num, "mid", to);
        int part5 = move(num - 1, from, to);
        return part1 + part2 + part3 + part4 + part5;
    }   
}


int main() {
    cin >> num;
    int steps = move(num, "left", "right");
    cout <<  "It will move " << steps << " steps." << endl;
    return 0;
}

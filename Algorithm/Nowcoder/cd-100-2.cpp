/*************************************************************************
> File Name: cd-100-2.cpp
> Author: yanzhiwei 
> Mail: 1931248856@qq.com
> Created Time: 2020年11月15日 星期日 11时01分28秒
************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef pair<int, int> PII;
queue<pair<int, int>> dog;
queue<pair<int, int>> cat;
int id = 0;
void add(int type, int num) {
    if (type == 1) {
        cat.push(PII(id++, num));
    } else {
        dog.push(PII(id++, num));
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
void pollAll() {
    while (!cat.empty() && !dog.empty())  {
        if (dog.front().first < cat.front().first) {
            cout << "dog " << dog.front().second << endl;
            dog.pop();
        } else {
            cout << "cat " << cat.front().second << endl;
            cat.pop();
        }
    }
    pollDog();
    pollCat();
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
int main() {
    int n, num;
    char op[16], type[16];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        memset(op, 0, sizeof(op));
        scanf("%s", op);
        if (strcmp(op, "add") == 0) {
            memset(type, 0, sizeof(type));
            scanf("%s%d", type, &num);
            if (strcmp(type, "cat") == 0) {
                add(1, num);
            } else {
                add(0, num);
            }
        } else if (strcmp(op, "pollAll") == 0) {
             pollAll();
        } else if (strcmp(op, "pollCat") == 0) {
             pollCat();
        } else if (strcmp(op, "pollDog") == 0) {
             pollDog();
        } else if (strcmp(op, "isEmpty") == 0) {
             isEmpty();
        } else if (strcmp(op, "isCatEmpty") == 0) {
             isCatEmpty();
        } else if (strcmp(op, "isDogEmpty") == 0) {
             isDogEmpty();
        }
    }

    return 0;
}


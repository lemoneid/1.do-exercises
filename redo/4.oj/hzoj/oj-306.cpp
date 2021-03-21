/*************************************************************************
	> File Name: oj-306.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月19日 星期五 14时18分31秒
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
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, int> check;
string dir[7][2];
struct Data {
    string str;
    int step;
};

int main() {
    string start, end;
    cin >> start >> end;
    int n = 0;
    while (cin >> dir[n][0] >> dir[n][1]) n++;
    queue<Data> que;
    que.push({start, 0});
    check[start] = 1;
    while (!que.empty()) {
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (1) {
                Data cur = que.front();
                long long x = cur.str.find(dir[i][0], j);
                j  = x + 1;
                if (x != string::npos) {
                    cur.str.replace(x, dir[i][0].size(), dir[i][1]);
                    cur.step++;
                    if (cur.str == end) {
                        cout << cur.step << endl;
                        return 0;
                    }
                    //cout << "1-5 : <" << cur.step << "> : " << cur.str << endl;
                    if (cur.step > 5) continue;
                    if (check[cur.str]) continue;
                    check[cur.str] = cur.step;
                    que.push(cur);
                } else {
                    break;
                }
            }
        }
        que.pop();
    }
    que.push({end, 0});
    check[end] = -1;
    while (!que.empty()) {
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (1) {
                Data cur = que.front();
                long long x = cur.str.find(dir[i][1], j);
                j  = x + 1;
                if (x != string::npos) {
                    cur.str.replace(x, dir[i][1].size(), dir[i][0]);
                    cur.step++;
                    if (cur.step > 5) continue;
                    //cout << "5-10 : <" << cur.step << "> : " << cur.str << endl;
                    if (check[cur.str] > 0) {
                        cout << check[cur.str] + cur.step<< endl;
                        return 0;
                    } 
                    check[cur.str] = -cur.step;
                    que.push(cur);
                } else {
                    break;
                }
            }
        }
        que.pop();
    }

    cout << "NO ANSWER!" << endl;


    return 0;
}

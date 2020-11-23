/*************************************************************************
	> File Name: cd-123.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 12时23分05秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, vector<string>> nexts;
unordered_map<string, int> dist;
unordered_set<string> strList;
vector<vector<string>> result;
string start, to;

//获取nexts
void getNexts() {
    string str = start;
    for (int i = 0; i < start.size(); ++i) {
        for (str[i] = 'a'; str[i] <= 'z'; str[i]++) {
            if (str[i] != start[i] && strList.find(str) != strList.end()) {
                nexts[start].push_back(str);
            }
        }
        str[i] = start[i];
    }
    for (auto iter = strList.begin(); iter != strList.end(); iter++) {
        for (int i = 0; i < iter->size(); ++i) {
            for (str[i] = 'a'; str[i] <= 'z'; str[i]++) {
                if (str[i] != (*iter)[i] && strList.find(str) != strList.end()) {
                    nexts[*iter].push_back(str);
                }
            }
            str[i] = (*iter)[i];
        }
    }
    return ;
}

//BFS
int getDist() {
    queue<string> que;
    que.push(start);
    dist[start] = 1;
    unordered_set<string> in_path;
    in_path.insert(start);
    string str;
    while (!que.empty()) {
        str = que.front();
        que.pop();
        for (auto &cur : nexts[str]) {
            if (in_path.find(cur) == in_path.end()) {
                que.push(cur);
                in_path.insert(cur);
                dist[cur] = dist[str] + 1; 
            }
        }
    }
    return dist[to];
}

//DFS
/*
void getPath(vector<string> &solution, int val) {
    string str = solution.back();
    if (str == to) {
        result.push_back(solution);
    } else {
        for (auto &cur : nexts[str]) {
            if (dist[str] + 1 == dist[cur] && (dist[cur] < val || dist[cur] == val && cur == to)) {
                solution.push_back(cur);
                getPath(solution, val);
                solution.pop_back();
            }
        }
    }
}
*/
void getPath(vector<string> &solution, int val) {
    string str = solution.back();
    if (str == to) {
        result.push_back(solution);
    } else {
        for (auto& setIter : nexts[str]) {
            if (dist[str] + 1 == dist[setIter] &&
                (dist[setIter] < val || dist[setIter] == val && setIter == to)) {
                solution.push_back(setIter);
                getPath(solution, val);
                solution.pop_back();
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin >> start >> to;
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        strList.insert(str);
    }
    if (strList.find(to) == strList.end()) {
        cout << "NO" << endl;
        return 0;
    }
    getNexts();
    int val = getDist();
    cout << val << endl;
    if (val == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<string> solution;
    solution.push_back(start);
    getPath(solution, val);
    vector<string> out_path;
    for (auto &path : result) {
        string str;
        for (int i = 0; i < path.size(); ++i) {
            if (i == 0) str = path[i];
            else str += " -> " + path[i];
        }
        out_path.push_back(str);
    }
    sort(out_path.begin(), out_path.end());
    for (auto &path : out_path) {
        cout << path << endl;
    }
    return 0;
}

/*************************************************************************
	> File Name: test.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月23日 星期一 12时51分17秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include<string>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;
unordered_map<string, vector<string>>nexts;
unordered_set<string> strList;
string start, to;
vector<vector<string>> result;
unordered_map<string, int>distances;

// 设置start的nexts
void getNexts() {
	string str = start;
	for (int i = 0; i < start.size(); i++) {
		for (str[i] = 'a'; str[i] <= 'z'; str[i]++) {
			if (str[i] != start[i] && strList.find(str) != strList.end()) {
				nexts[start].push_back(str);
			}
		}
		str[i] = start[i];
	}

	// 设置strLists里面的字符串的nexts
	unordered_set<string>::iterator setIter = strList.begin();
	for (auto setIter = strList.begin(); setIter != strList.end(); setIter++) {
		str = *setIter;
		for (int i = 0; i < setIter->size(); i++) {
			for (str[i] = 'a'; str[i] <= 'z'; str[i]++) {
				if (str[i] != (*setIter)[i] && strList.find(str) != strList.end()) {
					nexts[*setIter].push_back(str);
				}
			}
			str[i] = (*setIter)[i];
		}
	}
}

//BFS
int getDist() {
	queue<string> q;
	q.push(start);	
	distances[start] = 1;
	unordered_set<string> inPath;
	inPath.insert(start);
	string str;
	while (!q.empty()) {
		str = q.front();
		q.pop();
		for (auto& setIter : nexts[str]) {
            if (inPath.find(setIter) != inPath.end()) continue;
            q.push(setIter);
            inPath.insert(setIter);
            distances[setIter] = distances[str] + 1;
        }
	}
	return distances[to];
}

//DFS
void getPath(vector<string> &solution, int dist) {
	string str = solution.back();
	if (str == to) {
		result.push_back(solution);
	} else {
		for (auto& setIter : nexts[str]) {
			if (distances[str] + 1 == distances[setIter] &&
				(distances[setIter] < dist || distances[setIter] == dist && setIter == to)) {
				solution.push_back(setIter);
				getPath(solution, dist);
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
	for (int i = 0; i < n; i++) {
		cin >> str;
		strList.insert(str);
	}

	if (strList.find(to) == strList.end()) {
		cout << "NO" << endl;
		return 0;
	}
	getNexts();	
	int dist = getDist();
	if (dist == 0) {
		cout << "NO" << endl;
        return 0;
	}
    cout << "YES" << endl;
    vector<string> solution;
    solution.push_back(start);
    getPath(solution, dist);
    vector<string> out;
    for (auto& path : result) {
        string s = path[0];
        for (int i = 1; i < path.size(); i++) {
            s += " -> " + path[i];
        }
        out.push_back(s);
    }
    sort(out.begin(), out.end());
    for (auto& path : out)
    cout << path << endl;
    return 0;
}

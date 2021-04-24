/*************************************************************************
	> File Name: handle_brackets.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年04月22日 星期四 19时08分54秒
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
using namespace std;

const int MAX_N = 100000;

char buff[MAX_N];
char output[MAX_N];
const char *default_path = "./input";
map<string , string> mmap = {{"：", ":"}, {"，", ","},
    {"（", "("}, {"）",")"}, {"；", ";"}, {"．", "."},
    };

void readfile(char *);
void handle(string &, string , string);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        readfile(const_cast<char *>(default_path));
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        readfile(argv[i]);
    }
    return 0;
}

void readfile(char *pathname) {
    FILE *fp = NULL;
    if ((fp = fopen(pathname, "r+")) == NULL) {
        perror("fopen");
        return ;
    }
    memset(buff, 0, sizeof(buff));
    while (fgets(buff, sizeof(buff), fp) != NULL) {
       // printf("%s", buff);
        string s;
        for (int i = 0; buff[i]; i++) {
            s.push_back(buff[i]);
        }
        for (auto cur : mmap) {
            handle(s, cur.first, cur.second);
        }

        for (int i = 0; i < s.length(); i++) {
            cout << s[i];
            if (s[i] == ';' || s[i] == '.') {
                cout << endl;
            }
        }

        memset(buff, 0, sizeof(buff));
    }

    return ;
}

void handle(string &s, string from, string to) {
        unsigned long ind = 0;
        while ((ind = s.find(from)) != s.npos) {
            s.erase(ind, from.size());
            for (int i = 0; to[i]; i++) {
                s.insert(ind + i, 1, to[i]);
            }
        }
    
}

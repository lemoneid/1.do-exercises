/*************************************************************************
	> File Name: hj66.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月28日 星期二 18时09分53秒
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

vector<pair<string, string>> cmd_in = {
{"reset", ""},
{"reset","board"},
{"board", "add"},
{"board", "delet"},
{"reboot", "backplane"},
{"backplane", "abort"},
};

vector<string> cmd_out = {
"reset what",
"board fault",
"where to add",
"no board at all",
"impossible",
"install first",
};

const string unknow = "unknown command";

int main() {
    string input;
    while (getline(cin, input)) {
        string one, two;
        int i;
        for (i = 0; i < input.size(); i++) {
            if (input[i] == ' ') break;
        }
        if (i == input.size()) {
            if ((cmd_in[0].first).find(input) == cmd_in.end())  {
                cout << unknow << endl;
                continue;
            }
        }
        one = input.substr(0, i);
        two = input.substr(i + 1);
        for (int i = 0; i < cmd_in.size(); i++) {
        }
    }

}

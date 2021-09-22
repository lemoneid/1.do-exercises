/*************************************************************************
	> File Name: test.cpp
	> Author: yanzw
	> Mail: yanzw@pm.me
	> Created Time: 2021年09月20日 星期一 20时14分45秒
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

void Process_String(string str1, string str2, string strOutput)
{
    char Intput[] = {"0123456789abcdefABCDEF"};
    char Output[] = {"084C2A6E195D3B7F5D3B7F"};
    strOutput = str1 + str2; 
    string odd_str; 
    string even_str; 
    for (int i = 0; i < strOutput.size(); i++)
    {
        if (i % 2 == 0)
        {
            odd_str += strOutput[i];
        }
        else if (i % 2 == 1)
        {
            even_str += strOutput[i];
        }
    }
    sort(odd_str.begin(), odd_str.end()); //奇排序
    sort(even_str.begin(), even_str.end()); //偶排序
    for (int i = 0, j = 0, k = 0; i < strOutput.size(); i++)
    {
        if (i % 2 == 0)
        {
            strOutput[i] = odd_str[j];
            j++;
        }
        else if (i % 2 == 1)
        {
            strOutput[i] = even_str[k];
            k++;
        }
    }
    for (int i = 0; i < strOutput.size(); i++)
    {
        if ((strOutput[i] >= '0') && (strOutput[i] <= '9'))
        {
            strOutput[i] = Output[strOutput[i] - '0'];
        }
        else if ((strOutput[i] >= 'a') && (strOutput[i] <= 'f'))
        {
            strOutput[i] = Output[strOutput[i] - 'a' + 10];
        }
        else if ((strOutput[i] >= 'A') && (strOutput[i] <= 'F'))
        {
            strOutput[i] = Output[strOutput[i] - 'A' + 16];
        }
    }
    cout << strOutput << endl;
    return;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        string s = s1 + s2;

    }

    return 0;
}

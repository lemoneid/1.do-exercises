/*************************************************************************
	> File Name: cmp.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年12月06日 星期日 14时52分26秒
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
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;
    
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    for (char c : t) needs[c]++;
    
    int match = 0;
    
    while (right < s.size()) {
        char c1 = s[right];
        if (needs.count(c1)) {
            window[c1]++;
            if (window[c1] == needs[c1]) 
                match++;
        }
        right++;
        
        while (match == needs.size()) {
            if (right - left < minLen) {
                // 更新最小子串的位置和长度
                start = left;
                minLen = right - left;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ?
                "" : s.substr(start, minLen);
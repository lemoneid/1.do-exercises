/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        if (!len2) return 0;
        vector<int> next(len2);
        next[0] = -1;
        for (int i = 1, j = -1; i < len2; i++) {
            while (j != -1 && t[j + 1] != t[i]) j = next[j];
            if (t[j + 1] == t[i]) j += 1;
            next[i] = j;
        }
        for (int i = 0, j = -1; i < len1; i++) {
            while (j != -1 && t[j + 1] != s[i]) j = next[j];
            if (t[j + 1] == s[i]) j += 1;
            if (t[j + 1] == 0) return i - len2 + 1;
        }
        return -1;
    }
};
// @lc code=end


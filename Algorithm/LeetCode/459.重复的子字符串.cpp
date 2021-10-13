/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        vector<int> next(len + 5);
        next[0] = -1;
        for (int i = 1, j = -1; i < len; i++) {
            while (j != -1 && s[j + 1] != s[i]) j = next[j];
            if (s[j + 1] == s[i]) j++;
            next[i] = j;
        }
        if (next[len - 1] > -1 && len % (len - next[len -1] - 1) == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end


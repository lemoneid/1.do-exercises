/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[j] && j < s.size()) {
                j++;
            }
        }
        return j == s.size();
    }
};
// @lc code=end


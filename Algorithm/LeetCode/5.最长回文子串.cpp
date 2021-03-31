/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), ans = 0, ind = 0;
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for (int d = 0; d < len; d++) {
            for (int i = 0; i + d < len; i++) {
                int j = i + d;
                if (s[i] != s[j]) continue;
                if (d == 0 || d == 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j]) ans = max(ans, d + 1), ind = i;
            }
        }
        return s.substr(ind, ans);
    }
};
// @lc code=end


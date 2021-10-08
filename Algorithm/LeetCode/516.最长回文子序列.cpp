/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int> > dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
        }
        for (int l = 1; l < size; l++) {
            // starting index of window
            for (int i = 0; i < size - l; i++) {
                // ending index of window
                int j = i + l;
                if (j - i + 1 == 2) {
                    dp[i][j] = 1 + (s[i] == s[j]);
                } else {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    } else {
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][size - 1];
    }
};
// @lc code=end


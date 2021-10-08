/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 5, vector<int>(n + 5, 0));
        for (auto &cur : strs) {
            int zero = 0, one = 0;
            for (int i = 0; i < cur.size(); i++) {
                zero += cur[i] == '0';
                one += cur[i] == '1';
            }
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];

    }
};
// @lc code=end


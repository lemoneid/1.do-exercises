/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size < 2) return 0;
        vector<vector<int>> dp(size + 5, vector<int>(2 * k + 1, 0));
        for (int i = 1; i <= 2 * k; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < size; i++) {
            for (int j = 0; j  < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[size - 1][2 * k];
    }
};
// @lc code=end


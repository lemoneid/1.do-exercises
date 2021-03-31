/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //i day count have; 
        const int INF = -1000000;
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = INF;
        dp[0][1][1] = INF;
        dp[0][2][0] = INF;
        dp[0][2][1] = INF;
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][1] + prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][0] - prices[i], dp[i - 1][1][1]);
            dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1] + prices[i]);
            dp[i][2][1] = 0x80000000;
        }
        int ans = max(dp[n - 1][0][0], max(dp[n - 1][1][0], dp[n - 1][2][0]));
        return ans;

    }
};
// @lc code=end


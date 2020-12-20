/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount  + 1, amount + 1);
            for (int i = 0; i <= amount; ++i) {
                for (int val : coins) {
                    if (val > i) continue;
                    dp[i] = min(dp[i], dp[i - val] + 1);
                }
            }
            return dp[amount] == amount + 1 ?  -1 : dp[amount];
    }
};
// @lc code=end


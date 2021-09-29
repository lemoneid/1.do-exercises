/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 5, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = 2; j * j <= n; j++) {
                if (i % j) continue;
                dp[i] = min(dp[j] + dp[i / j], dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end


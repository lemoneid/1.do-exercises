/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
        
        for (int j = 2; j <= n; j++) {
            for (int i = j - 1; i >= 1; i--) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
                }
                dp[i][j] = min(dp[i][j], min(i + dp[i + 1][j], j + dp[i][j - 1]));
            }
        }
        return dp[1][n];

    }
private :
    int calculate(int low, int high) {
        if (low >= high) return 0;
        int minres = 0x7fffffff;
        for (int i = (low + high) / 2; i <= high; ++i) {
            int res = max(calculate(low, i - 1), calculate(i + 1, high)) + i;
            minres = min(minres, res);
        }
        return minres;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<vector<bool>> check(len, vector<bool>(len, false));
        for (int d = 0; d < len; d++) {
            for (int i = 0; i + d < len; i++) {
                int j = i + d;
                if (s[i] != s[j]) continue;
                if (d == 0 || d == 1) check[i][j] = true;
                else check[i][j] = check[i + 1][j - 1];
            }
        }
        vector<int> dp(len, 0);
        for (int i = 0; i < len; i++) {
            if (check[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if (check[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len - 1];

    }
};
// @lc code=end


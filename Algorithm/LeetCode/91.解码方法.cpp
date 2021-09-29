/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (!length) return 0;
        int prev = s[0] - '0';
        if (!prev) return 0;
        if (length == 1) return 1;
        vector<int> dp(length + 5, 0);
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= length; i++) {
            int cur = s[i - 1] - '0';
            if (!cur && (prev == 0 || prev > 2)) return 0;
            if ((prev == 1) || (prev == 2 && cur < 7)) {
                if (cur) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 2];
                }
            } else {
                dp[i] = dp[i - 1];
            }
            prev = cur;
        }
        return dp[length];
    }
};
// @lc code=end


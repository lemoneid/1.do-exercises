/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<int> dp(len2 + 5, 0);
        for (int j = 1; j <= len2; j++) {
          dp[j] = (text1[0] == text2[j - 1] ? 1 : dp[j - 1]);
        }
        for (int i = 2; i <= len1; i++) {
            int pre = 0;
            for (int j = 1; j <= len2; j++) {
                int temp = dp[j];
              if (text1[i - 1] == text2[j - 1]) {
                dp[j] = pre + 1;
              } else {
                dp[j] = max(dp[j], dp[j - 1]);
              }
              pre = temp;
            }
        }
        return dp[len2];
    }
};
// @lc code=end


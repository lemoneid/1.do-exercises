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
        //dp[0][0] = 1;
        for (int i = 1; i <= len2; i++) {
            dp[i] = text1[0] == text2[i - 1];
        }
        for (int i = 2; i <= len1; i++) {
            int pre = 0;
            for (int j = 1; j <= len2; j++) {
                int tmp = dp[i]; 
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i] = pre + 1;
                } else {
                    dp[i] = max(dp[i], dp[i - 1]);
                }
                pre = tmp; 
            }
        }
        return dp[len2];
    }
};
// @lc code=end


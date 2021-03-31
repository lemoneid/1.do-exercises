/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size(), len2 = B.size();
        int ans = 0;
        vector<int> dp(len2 + 1);
        dp[0] = 0;
        for (int j = 1; j <= len2; j++) {
            dp[j] = !!(A[0] == B[j - 1]);
            ans = max(ans, dp[j]);
        }
        int pre = 0;
        for (int i = 2; i <= len1; i++) {
            for (int j = len2; j >= 1; j--){
                if (A[i - 1] != B[j - 1]) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j - 1] + 1;
                }
                ans = max(ans, dp[j]);
            }
        }
        return ans;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto arr = triangle;
        int row = arr.size();
        int size = arr[row - 1].size();
        vector<int> dp(size + 5, 0);
        for (int i = 0; i < size; i++) {
            dp[i] = arr[row - 1][i];
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + arr[i][j];
            }
        }
        return dp[0];
    }
};
// @lc code=end


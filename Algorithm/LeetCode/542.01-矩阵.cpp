/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int row = mat.size(), col = row ? mat[0].size() : 0;
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX - 1));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        for (int i = row - 1; i >= 0; i--) {
          for (int j = col - 1; j >= 0; j--) {
            if (mat[i][j] == 0) {
              dp[i][j] = 0;
            } else {
              if (i < row - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
              if (j < col - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
          }
        }
        return dp;

    }
};
// @lc code=end


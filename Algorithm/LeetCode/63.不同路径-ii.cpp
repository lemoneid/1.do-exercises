/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto arr = obstacleGrid;
        int row = arr.size();
        int col = arr[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 0));
        dp[0][0] = arr[0][0] == 0;
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] && arr[i][0] == 0; 
        }
        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i - 1] && arr[0][i] == 0; 
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (arr[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];


    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix);
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[j][col - i - 1] = ans[i][j];
            }
        }
        return ;
    }
};
// @lc code=end

`
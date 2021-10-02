/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = row ? matrix[0].size() : 0;
        bool ans = false;
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                ans = true;
                break;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }

        }
        return ans;
        
    }
};
// @lc code=end


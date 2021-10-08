/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        int row = matrix.size(), col = row ? matrix[0].size() : 0;
        int l = 0, r = row * col - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2 ;
            int val = matrix[mid / col][mid % col];
            if (target == val) return true;
            if (target > val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end


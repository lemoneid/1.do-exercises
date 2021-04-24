/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        vector<int> ans((right + 1) * (down + 1));
        int ind = 0;
        while (1) {
            for (int i = left; i <= right; i++) {
                ans[ind++] = matrix[up][i];
            }
            if (++up > down) break;
            for (int i = up; i <= down; i++) {
                ans[ind++] = matrix[i][right];
            }
            if (--right < left) break;
            for (int i = right; i >= left; --i) {
                ans[ind++] = matrix[down][i];
            }
            if (--down < up) break;
            for (int i = down; i >= up; --i) {
                ans[ind++] = matrix[i][left];
            }
            if (++left > right) break;
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int l = matrix[0][0], r = matrix[row - 1][col - 1];
        wh, row, colile (l < r) {
            int mid = (l + r) >> 1;
            if (getCount(matrix, mid, row, col) < k) l = mid + 1;
            else r = mid;
        }
        return r;

    }
    int getCount(vector<vector<int>> &arr, int val, int row, int col) {
        int x = 0, y = col - 1;
        int cnt = 0;
        while (x < row && y >= 0) {
            if (arr[x][y] <= val) {
                cnt += y + 1;
                x++;
            } else {
                y--;
            }
        }
        return cnt;
    }
};
// @lc code=end


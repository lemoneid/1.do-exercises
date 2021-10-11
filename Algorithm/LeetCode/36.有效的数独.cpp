/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr int N = 9;
        vector<vector<bool>> row(N, vector<bool>(N, false));
        vector<vector<bool>> col(N, vector<bool>(N, false));
        vector<vector<bool>> box(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                int idx = i / 3 * 3 + j / 3;
                if (row[i][val] || col[val][j] || box[idx][val]) {
                    return false;
                }
                row[i][val] = true;
                col[val][j] = true;
                box[idx][val] = true;
            }
        }
        return true;
    }
};
// @lc code=end


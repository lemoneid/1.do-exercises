/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (!board.size() || !board[0].size()) return false;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> used(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                used[i][j] = true;
                if (dfs(i, j, 1, board, word, used)) return true;
                used[i][j] = false;
            }
        }
        return false;
    }
private:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    bool dfs(int x, int y, int start, const vector<vector<char>>&board, 
            const string &word, vector<vector<bool>>& used) {
        if (start == word.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];
            if (new_x < 0 || new_y < 0 || new_x >= board.size() || new_y >= board[0].size()) {
                continue;
            }
            if (board[new_x][new_y] != word[start]) continue;
            if (used[new_x][new_y]) continue;
            used[new_x][new_y] = true;
            if (dfs(new_x, new_y, start + 1, board, word, used)) return true;
            used[new_x][new_y] = false;
        }
        return false;
    }
};
// @lc code=end


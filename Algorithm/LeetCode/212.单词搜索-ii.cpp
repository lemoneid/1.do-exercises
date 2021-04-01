/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int row = board.size(), col = board[0].size();
        check.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < words.size(); i++) {
            check.assign(row * col, false); 
            if (dfs(board, words[i], 0, 0, 0)) ans.push_back(words[i]);
        }
        return ans;
    }
private :
    bool dfs(vector<vector<char>> &board, const string &word, int start, int x, int y) {
        if (start == word.size()) return true;
        int row = board.size(), col = board[0].size();
        if (start == 0) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (board[i][j] != word[0]) continue;
                    check[i][j] = true;
                    if (dfs(board, word, 1, i, j)) return true;
                    check[i][j] = false;
                }
            }
            return false;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx >= row || yy >= col) continue;
            if (check[xx][yy] || board[xx][yy] != word[start]) continue;
            check[xx][yy] = true;
            if (dfs(board, word, start + 1, xx, yy)) {
                return true;
            }
        }
        return false;
    }
    vector<vector<bool>> check;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

};
// @lc code=end


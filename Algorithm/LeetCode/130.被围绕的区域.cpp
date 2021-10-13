/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size()) return ;
        int n = board.size();
        int m = board[0].size();
        queue<PII> que;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') que.push(PII(i, 0));
            if (board[i][m - 1] == 'O') que.push(PII(i, m - 1));
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') que.push(PII(0, j));
            if (board[n - 1][j] == 'O') que.push(PII(n - 1, j));
        }
        while (!que.empty()) {
            PII cur = que.front();
             que.pop();
             board[cur.first][cur.second] = 'A';
             for (int i = 0; i < 4; i++) {
                 int x = cur.first + dir[i][0];
                 int y = cur.second + dir[i][1];
                 if (x < 0 || y < 0 || x >= n || y >= m) continue;
                 if (board[x][y] != 'O') continue;
                 que.push(PII(x, y));
             }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
            }
        }
        return ;
    }
private:
    typedef pair<int,int> PII;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
};
// @lc code=end


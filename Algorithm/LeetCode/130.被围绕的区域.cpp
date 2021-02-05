/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class UnionSet {
public :
    vector<int> father;
    void init(int n) {
        father.clear();
        for (int i = 0; i <= n; ++i) {
            father.push_back(i);
        }
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        father[get(a)] = get(b);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (!board.size() || !board[0].size()) return ;
        n = board.size();
        m = board[0].size();
        u.init(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << i << ":" << j << endl;
                if (board[i][j] != 'O') continue;
                if (!i || !j || i == n - 1 || j == m - 1) {
                    u.merge(ind(i, j), 0);
                }
                if (i && board[i - 1][j] == 'O') {
                    u.merge(ind(i, j), ind(i - 1, j));
                }
                if (j && board[i][j - 1] == 'O') {
                    u.merge(ind(i, j), ind(i, j - 1));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != 'O') continue;
                if (u.get(ind(i, j)) != u.get(0)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    inline int ind(int i, int j) {
        return i * m + j + 1;
    }
private :
    int n, m;
    UnionSet u;
};
// @lc code=end


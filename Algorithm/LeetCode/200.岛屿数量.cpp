/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Unionset {
public :
    vector<int> fa;
    void init(int n) {
        fa.clear();
        for (int i = 0; i <= n; ++i) fa.push_back(i);
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        u.init(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '1') continue;
                if (i && grid[i - 1][j] == '1') u.merge(ind(i - 1, j), ind(i, j));
                if (j && grid[i][j - 1] == '1') u.merge(ind(i, j - 1), ind(i , j));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '1') continue;
                if (u.get(ind(i, j)) == ind(i, j)) ans += 1;
            }
        }
        return ans;
    }
private :
    int n, m;
    Unionset u;
    inline int ind(int i, int j) {
        return i * m + j + 1;
    }
};
// @lc code=end


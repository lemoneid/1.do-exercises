/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }
        vector<vector<int>> ans;
        int n = heights.size(), m = (n ? heights[0].size() : 0);
        vector<vector<bool>> can_reach_p(n, vector<bool>(m, false));
        vector<vector<bool>> can_reach_a(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            dfs(heights, can_reach_p, i, 0);
            dfs(heights, can_reach_a, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, can_reach_p, 0, i);
            dfs(heights, can_reach_a, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (can_reach_a[i][j] && can_reach_p[i][j]) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>> &can_reach,int r, int c) {
        if (can_reach[r][c]) return ;
        can_reach[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if (x < 0 || x >= heights.size()) continue;
            if (y < 0 || y >= heights[0].size()) continue;
            if (heights[x][y] < heights[r][c]) continue;
            dfs(heights, can_reach, x, y);
        }
        return ;
    }
};
// @lc code=end


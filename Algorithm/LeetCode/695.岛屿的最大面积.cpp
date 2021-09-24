/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int n = grid.size(), m = n ? grid[0].size() : 0;
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

        int x, y, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;
                int area = 1;
                grid[i][j] = 0;
                stack<pair<int, int >> valid;
                valid.push({i, j});
                while (!valid.empty()) {
                    auto cur = valid.top();
                    valid.pop();
                    for (int k = 0; k < 4; k++) {
                        x = cur.first + dir[k][0];
                        y = cur.second + dir[k][1];
                        if (x < 0 || y < 0 || x >= n || y >= m) continue;
                        if (grid[x][y] == 0) continue;
                        ++area;
                        grid[x][y] = 0;
                        valid.push({x, y});
                    }
                }
                ans = max(area, ans);

            }
        }
        return ans;

    }
};
// @lc code=end


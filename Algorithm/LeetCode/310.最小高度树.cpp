/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 1) return {0};
        if (n == 2) return {0, 1};
        vector<int> in_degree(n, 0);
        vector<vector<int>> graph(n);
        for (int i = 0, u, v; i < edges.size(); i++) {
            u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            in_degree[u]++;
            in_degree[v]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 1) que.push(i), in_degree[i] = 0;
        }
        int cnt = que.size();
        while (n > 2) {
            n -= cnt;
            for (int i = 0; i < cnt; i++) {
                int now = que.front();
                que.pop();
                for (int i = 0, v; i < graph[now].size(); i++) {
                    v = graph[now][i];
                    if (in_degree[v] == 0) continue;
                    in_degree[v]--;
                    if (in_degree[v] == 1) {
                        in_degree[v] = 0;
                        que.push(v);
                    } 
                }
            }
            cnt = que.size();
        }
        vector<int> ans;
        while (!que.empty()) {
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};
// @lc code=end


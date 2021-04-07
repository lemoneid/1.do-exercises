/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> in_degree(numCourses);
        for (auto cur : prerequisites) {
            edge[cur[1]].push_back(cur[0]);
            in_degree[cur[0]]++;
        }
        vector<int> ans;
        queue<int> que;
        for (int i = 0;  i < numCourses; i++) {
            if (in_degree[i] == 0) {
                que.push(i);
                ans.push_back(i);
            }
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < edge[now].size(); i++) {
                int v = edge[now][i];
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }
        if (ans.size() == numCourses) return ans;
        return vector<int>(0);

    }
};
// @lc code=end


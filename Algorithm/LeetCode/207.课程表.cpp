/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto cur : prerequisites) {
            edge[cur[1]].push_back(cur[0]);
            in_degree[cur[0]]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (int i = 0; i < edge[now].size(); i++) {
                int v = edge[now][i];
                in_degree[v]--;
                if (in_degree[v] == 0) que.push(v);
            }
        }
        for (int i = 0;  i < numCourses; i++) {
            if (in_degree[i])  return false;
        }
        return true;
    }
};
// @lc code=end


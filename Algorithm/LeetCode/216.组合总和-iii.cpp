/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(n, k, 1, 0);
        return result;
    }
private: 
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(int n, int k, int start, int sum) {
        if (sum > n) return ;
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return ;
        }
        for (int i = start; i <=  9 - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1, sum + i);
            path.pop_back();
        }
    }

};
// @lc code=end


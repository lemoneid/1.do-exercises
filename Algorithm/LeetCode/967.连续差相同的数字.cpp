/*
 * @lc app=leetcode.cn id=967 lang=cpp
 *
 * [967] 连续差相同的数字
 */

// @lc code=start
class Solution {
public:
    void dfs(int val, int left, int k) {
        if (left == 0) {
            ans.push_back(val);
            return ;
        }
        int x = val % 10;
        if (x - k >= 0) dfs(val * 10 + x - k, left - 1, k);
        if (k == 0) return ;
        if (x + k < 10) dfs(val * 10 + x + k, left - 1, k);

    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; i++) {
            dfs(i, n - 1, k);
        }
        return ans;
    }
    vector<int> ans;
};
// @lc code=end


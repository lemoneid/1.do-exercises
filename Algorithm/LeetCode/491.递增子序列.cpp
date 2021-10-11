/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtrack(nums, 0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    const int MAX_N = 201;
    const int increase = 100;
    void backtrack(vector<int>&nums, int start) {
        if (path.size() > 1) {
            result.push_back(path);
        }
        vector<bool> used(MAX_N + 5, false);
        for (int i = start; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                || used[nums[i] + increase] == true) {
                continue;
            }
            path.push_back(nums[i]);
            used[nums[i] + increase] = true;
            backtrack(nums, i + 1);
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end


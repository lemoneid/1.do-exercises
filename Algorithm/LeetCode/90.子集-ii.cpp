/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        result.clear();
        path.clear();
        backtracking(nums, 0, used);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int start, vector<bool> &used) {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end


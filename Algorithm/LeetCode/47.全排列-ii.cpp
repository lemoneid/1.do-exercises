/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>&nums, vector<bool>&used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end


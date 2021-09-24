/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        backtarcking(nums, 0, ans);
        return ans;
    }
    void backtarcking(vector<int>&nums, int index, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            backtarcking(nums, index + 1, ans);
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end


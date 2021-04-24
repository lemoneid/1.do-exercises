/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        handle(candidates, 0, target, arr);
        return ans;
    }
private :
    void handle(vector<int> &nums, int start, int target, vector<int> &arr) {
        if (target == 0) {
            ans.push_back(arr);
            return ;
        }
        for (int i = start; i < nums.size() && target >= nums[i]; i++) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            arr.push_back(nums[i]);
            handle(nums, i + 1, target - nums[i], arr);
            arr.pop_back();
        }
        return ;
    }
    vector<vector<int>> ans;
};
// @lc code=end


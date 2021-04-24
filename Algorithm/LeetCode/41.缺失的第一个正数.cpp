/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //l : 维护1-l的值
        //r : 最优的情况的范围
        int l = 0, r = nums.size();
        while (l < r) {
            if (nums[l] == l + 1) {
                l++;
            } else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
                nums[l] = nums[--r];
            } else {
                int idx = nums[l] - 1;
                swap(nums[l], nums[idx]);
            }
        }
        return l + 1;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int handle(vector<int> &nums, int l, int r) {
        vector<int> dp(nums.size(), 0);
        dp[l] = nums[l];
        dp[l + 1] = max(nums[l], nums[l + 1]);
        for (int i = l + 2; i < r; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[r - 1];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        return max(handle(nums, 0, size - 1), handle(nums, 1, size));
    }
};
// @lc code=end


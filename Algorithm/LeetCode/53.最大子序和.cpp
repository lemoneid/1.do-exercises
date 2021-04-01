/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int pre = min(0, nums[0]), sum = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum - pre);
            pre = min(pre, sum);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        int *dp = new int[len];
        for (int i = 0; i < len; i++) dp[i] = 0;
        for (int i = 2; i < len; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        long long total = 0;
        for (int i = 2; i < len; i++) {
            total += dp[i];
        }
        return total;
    }
};
// @lc code=end


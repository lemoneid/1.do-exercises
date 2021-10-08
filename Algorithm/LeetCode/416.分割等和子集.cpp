/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 1) return false;
        sum /= 2;
        vector<int> dp(sum + 5, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[sum] == sum;
    }
};
// @lc code=end


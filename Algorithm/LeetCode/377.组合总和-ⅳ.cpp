/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 5, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
                if (dp[i] > INT_MAX) break;
            }
        }
        return dp[target];
    }
};
// @lc code=end


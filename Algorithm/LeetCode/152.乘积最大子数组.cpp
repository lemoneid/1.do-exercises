/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result, mmax, mmin;
        result = mmax = mmin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int p = mmax * nums[i];
            int q = mmin * nums[i];
            mmax = max(nums[i], max(p, q));
            mmin = min(nums[i], min(p, q));
            result = max(result, mmax);
        }
        return result;

    }
};
// @lc code=end


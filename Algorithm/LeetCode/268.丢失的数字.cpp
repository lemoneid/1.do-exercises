/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] != nums.size()) {
                int a = nums[i], b = nums[a];
                nums[a] = a, nums[i] = b;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i - nums[i]) return i;
        }
        return nums.size();
        */
       int res = nums.size();
       for (int i = 0; i < nums.size(); ++i) {
           res ^= i;
           res ^= nums[i];
       }
       return res;

    }
};
// @lc code=end


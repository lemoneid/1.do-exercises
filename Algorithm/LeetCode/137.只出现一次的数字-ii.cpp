/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, a1, b1;
        for (int i = 0, c; i < nums.size(); i++) {
            c = nums[i];
            a1 = (a & ~b & ~c) | (~a & b & c);
            b1 = (~a & b & ~c) | (~a & ~b & c);
            a = a1;
            b = b1;
        }
        return b;
    }
};
// @lc code=end


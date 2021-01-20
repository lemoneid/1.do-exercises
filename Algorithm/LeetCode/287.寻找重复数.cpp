/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p = nums[0], q = nums[0];
        do {
            p = nums[p];
            q = nums[nums[q]];
        } while (p != q);
        p = nums[0];
        while (p != q) {
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};
// @lc code=end


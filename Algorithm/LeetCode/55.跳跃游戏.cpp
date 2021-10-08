/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > right) return false;
            right = max(right, nums[i] + i);
            if (right >= nums.size() - 1) return true;
        }
        return true;
    }
};
// @lc code=end


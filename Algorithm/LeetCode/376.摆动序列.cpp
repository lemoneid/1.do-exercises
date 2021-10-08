/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int result = 1;
        int curDiff = 0;
        int preDiff = 0;
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            if (curDiff == 0) continue;
            if (curDiff * preDiff <= 0) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end


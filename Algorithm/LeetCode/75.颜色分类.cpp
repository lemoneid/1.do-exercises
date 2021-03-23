/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = -1, b = 0, c = nums.size();
        while (b < c) {
            if (nums[b] == 0) {
                swap(nums[++a], nums[b++]);
            } else if (nums[b] == 2) {
                swap(nums[--c], nums[b]);
            } else {
                b++;
            }
        }


    }
};
// @lc code=end


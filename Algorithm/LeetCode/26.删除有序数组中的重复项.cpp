/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int cur = 0, i = 1, len = nums.size();
        while (i < len) {
            while (i < len && nums[i] == nums[cur]) i++;
            if (i >= len) break;
            nums[++cur] = nums[i++];
        }
        return cur + 1;
    }
};
// @lc code=end


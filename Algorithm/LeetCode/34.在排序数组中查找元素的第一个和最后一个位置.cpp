/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1 = findTheFirst(nums, target + 1) - 1;
        int p2 = findTheFirst(nums, target);
        vector<int> ans;
        if (p1 >= p2) {
            ans = {p2, p1};
        } else {
            ans  = {-1, -1};
        }
        return ans;
    }
    int findTheFirst(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end


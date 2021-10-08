/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size == 1) return 1;
        vector<int> nums(size, 1);
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        }
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                nums[i] = max(nums[i], nums[i + 1] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += nums[i];
        }
        return result;
    }
};
// @lc code=end


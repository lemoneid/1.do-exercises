/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return abs(a) > abs(b);
        });
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) nums[size - 1] *= -1;
        for (int i = 0; i < size; i++) {
            result += nums[i];
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size(), flag = 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ans = 0;

        for (auto a = nums.begin(); a != prev(nums.end(), 2); ++a) {
            auto b = next(a);
            auto c = prev(nums.end());
            while (b < c) {
                int sum = *a + *b + *c;
                int gap = abs(sum - target);
                if (gap < diff) {
                    ans = sum;
                    diff = gap;
                }
                sum < target ? ++b : --c;
            }

        }
        return ans;
        for (int i = 0; i < size - 2; i++) {
            // value = target - nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = size - 1;
            while (l < r) {
                int  sum = nums[l] + nums[r] + nums[i];
                if (sum == target) {
                    flag = 1;
                    ans = sum;
                    break;
                }
                if (abs(sum - target) < diff) {
                    ans = sum;
                    diff = abs(sum - target);
                }
                sum < target ? l++ : r--;
            }
            if (flag) break;
        }

        return ans;
    }
};
// @lc code=end


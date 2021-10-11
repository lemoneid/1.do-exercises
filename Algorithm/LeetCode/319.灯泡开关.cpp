/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
        int result = 0;
        vector<int> nums(n + 5, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                nums[j] = !nums[j];
            }
        }
        for (int i = 1; i <= n; i++) {
            result += nums[i];
        }
    }
};
// @lc code=end


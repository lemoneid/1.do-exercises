/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto &cur : stones) {
            sum += cur;
        }
        vector<int> dp(sum + 5, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        int result = sum;
        for (int j = sum / 2; j >= 0; j--) {
            if (dp[j] == j) {
                result = sum - 2 * j;
                break;
            }
        }
        return result;
    }
};
// @lc code=end


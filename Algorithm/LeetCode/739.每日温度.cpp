/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size, 0);
        stack<int> indices;
        for (int i = 0; i < size; ++i) {
            while (!indices.empty()) {
                int pre_index = indices.top();
                if (temperatures[i] <= temperatures[pre_index]) {
                    break;
                }
                indices.pop();
                ans[pre_index] = i - pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};
// @lc code=end


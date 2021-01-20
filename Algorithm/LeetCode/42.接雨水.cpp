/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int cur = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int w = i - stk.top() - 1;
                int h = min(height[i], height[stk.top()]) - height[cur];
                ans += w * h;
            }
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;
        int size = height.size(), ans = 0, top = -1;
        int *stk = new int[size + 5];
        for (int i = 0; i < size; i++) {
            while (top != -1 && height[i] > height[stk[top]]) {
                int bottom = height[stk[top]];
                if ((--top) == -1) break;
                int h = min(height[i], height[stk[top]]) - bottom;
                int len = i - stk[top] - 1;
                ans += h * len;
            }
            stk[++top] = i;
        }
        delete[] stk;
        return ans;
    }
};
// @lc code=end


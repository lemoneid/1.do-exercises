/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') stk.push(i);
            else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    int left = stk.empty() ? -1 : stk.top();
                    ans = max(ans, i - left);
                } else {
                    stk.push(i);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


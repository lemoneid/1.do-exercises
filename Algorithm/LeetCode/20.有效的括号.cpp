/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.length() & 1) return false;
        stack<char> stk;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty() || stk.top() != pairs[s[i]]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end


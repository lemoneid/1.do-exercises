/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        return parseExpr(s, 0);
    }
    int parseExpr(const string &s, int i) {
        char op = '+';
        long left = 0, right = 0;
        while (i < s.length()) {
            if (s[i] == ' ') continue;
            long n = parseNum(s, i);
            switch (op) {
                case '+' : left += right; right = n; break;
                case '-' : left += right; right = -n; break;
                case '*' : right *= n; break;
                case '/' : right /= n; break;
            }
            if (i < s.length()) {
                op = s[i];
            }
            ++i;
        }
        return left + right;
    }
    long parseNum(const string &s, int &i) {
        long n = 0;
        while (i < s.length() && isdigit(s[i])) {
            n = n * 10 + (s[i++] - '0');
        }
        return n;
    }
};
// @lc code=end


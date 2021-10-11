/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string express) {
        std::stack<int> path;
        int sign = 1, res = 0;
        int length = express.length();
        for (int i = 0; i < length; i++) {
            char ch = express[i];
            if (std::isdigit(ch)) {
                int value = ch - '0';
                while (i + 1 < length && std::isdigit(express[i + 1])) {
                    ++i;
                    value = value * 10  + (express[i] - '0');
                }
                res = res + sign * value;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                path.push(res);
                path.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                int op = path.top(); path.pop();
                int num = path.top(); path.pop();
                res = op * res + num;
            }
        }
        return res;
    }
};
// @lc code=end


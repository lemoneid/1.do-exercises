/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<int(int, int)>> calc {
            {"+", [](int a, int b) {return a + b; }},
            {"-", [](int a, int b) {return a - b; }},
            {"*", [](int a, int b) {return a * b; }},
            {"/", [](int a, int b) {return a / b; }}
        };
        stack<int> s;
        for (auto &cur : tokens) {
            if (!calc.count(cur)) {
                s.push(stoi(cur));
            } else {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(calc[cur](y, x));
            }
        }
        return s.top();
    }
};
// @lc code=end


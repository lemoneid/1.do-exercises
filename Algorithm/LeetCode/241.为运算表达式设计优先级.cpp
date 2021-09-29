/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if (expression.empty()) return {};
        vector<int> ways;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.length() - i - 1));
                for (const int &l : left) {
                    for (const int &r : right) {
                        switch (expression[i]) {
                            case '+' : ways.push_back(l + r); break;
                            case '-' : ways.push_back(l - r); break;
                            case '*' : ways.push_back(l * r); break;
                        }
                    }
                }
            }
        }
        if (ways.empty()) ways.push_back(stoi(expression));
        return ways;
    }
};
// @lc code=end


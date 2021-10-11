/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        char op = '+';
        std::stack<int> nums;
        int length = s.size();
        int value = 0;
        for (int i = 0; i < length; i++) {
            if (::isdigit(s[i])) {
              while (i < s.length() && isdigit(s[i])) {
                value = value * 10 + (s[i++] - '0');
              }
            }
            if (!(s[i] != ' ' || i == length - 1)) continue;
            switch (op) {
                cout << "s[i] = " << s[i] << " | " << op << endl;
                case '+' : nums.push(value); break;
                case '-' : nums.push(-value); break;
                case '*' : {
                    int firstNumber = nums.top(); 
                    nums.pop();
                    nums.push(firstNumber * value);
                }; break;
                case '/' : {
                    int firstNumber = nums.top(); 
                    nums.pop();
                    nums.push(firstNumber / value);
                }; break;
            }
            op = s[i];
            value = 0;
        }
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
// @lc code=end


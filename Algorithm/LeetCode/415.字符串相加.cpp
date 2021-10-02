/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty()) return num2;
        if (num2.empty()) return num1;
        int len1 = num1.size(), len2 = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int addbit = 0, val = 0;
        string output;
        for (int i = 0, I = max(len1, len2); i < I; i++) {
            val = i < len1 ? num1[i] - '0' : 0;
            val += i < len2 ? num2[i] - '0' : 0;
            val += addbit;
            output += to_string(val % 10);
            addbit = val / 10;
        }
        if (addbit) output += "1";
        reverse(output.begin(), output.end());
        return output;

    }
};
// @lc code=end


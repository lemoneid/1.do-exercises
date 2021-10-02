/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool flag = num < 0;
        if (flag) num = -num;
        string ans;
        while (num) {
            ans = to_string(num % 7) + ans;
            num /= 7;
        }
        return flag ? "-" + ans : ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, id = 0;
        if (s[0] == '+' || s[0] == '-') {
                if (s[0] == '-') sign = -1;
                id++;
        }    
        while (s[id]) {
            
        }
    }
};
// @lc code=end


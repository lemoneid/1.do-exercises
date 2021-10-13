/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        unsigned int val = num;
        string str;
        char hash[17] = "0123456789abcdef";
        do {
            str += hash[val % 16];
            val /= 16;
        } while (val);
        return {str.rbegin(), str.rend()};

    }
};
// @lc code=end


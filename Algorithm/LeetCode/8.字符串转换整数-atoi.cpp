/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int flag = 1;
        int ind = 0;
        const int MAX = 0x7fffffff;
        const int MIN = 0x80000000;
        while (s[ind] && s[ind] == ' ') ind++;
        if (!s[ind]) return 0;
        if (s[ind] == '+') ind++;
        else if (s[ind] == '-') flag = -1, ind++;
        long long ans = 0;
        while (s[ind]) {
            if (s[ind] < '0' || s[ind] > '9') break;
            ans = ans * 10 + s[ind] - '0';
            if (flag == 1 && ans >= MAX) {
                return MAX;
            }
            if (flag == -1 && flag * ans <= MIN) {
                return MIN;
            }
            ind++;
        }
        return (int)(ans * flag);

    }
};
// @lc code=end


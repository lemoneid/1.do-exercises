/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res, cur = countAndSay(n - 1);
        int i = 0, cnt = 1;
        while (cur[i]) {
            while (cur[i + 1] && cur[i] == cur[i + 1]) {
                i++;
                cnt++;
            }
            res += to_string(cnt);
            res += cur[i];
            cnt = 1;
            i++;
        }
        return res;
    }
};
// @lc code=end


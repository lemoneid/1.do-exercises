/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        int result = 0;

        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }

        if (dividend == INT_MIN) {
            dividend = neg ? dividend + divisor : dividend - divisor;
            result++;
        }
        dividend = std::abs(dividend);
        divisor = std::abs(divisor);
        result += __divide(dividend, divisor);

        return neg ? -result : result;
    }
private:
    int __divide(int dividend, int divisor) {
        if (dividend < divisor) {
            return 0;
        }
        int cnt = 1;
        int cur = divisor;
        while (dividend - cur >= cur) {
            cnt += cnt;
            cur += cur;
        }
        return  cnt == 1 ? cnt : cnt + __divide(dividend - cur, divisor);
    }
};
// @lc code=end


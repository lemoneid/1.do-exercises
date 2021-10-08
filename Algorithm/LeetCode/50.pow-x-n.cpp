/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) return x;
        if (n == 0) return 1;
        long long cnt = n;
        if (n < 0) {
            cnt = -cnt;
            x = 1 / x;
        }
        double result = 1.0;
        while (cnt) {
            if (cnt & 1) result *= x;
            x *= x;
            cnt >>= 1;
        }
        return result;
    }
};
// @lc code=end


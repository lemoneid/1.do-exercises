/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:

    long long quick_pow(int a, int b) {
        long long ans = 0;
        while (b) {
            if (b & 1) ans *= a;
            a *= a;
            b >>= 1;
        }
        return ans;
    }

    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;

    }
};
// @lc code=end


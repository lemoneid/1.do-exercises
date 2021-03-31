/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        m -= 1, n -= 1;
        int b = m + n;
        int a = min(m, n);
        long long ans = 1;
        for (int i = b, I = b - a + 1; i >= I; i--) {
           ans *= i;
           while (a > 1 && ans % a == 0)  {
               ans /= a;
               a--;
           }
        }
        return ans;
    }
};
// @lc code=end


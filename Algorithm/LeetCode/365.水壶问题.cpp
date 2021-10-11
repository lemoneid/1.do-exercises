/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z - x <= y && z % gcd(x, y) == 0);

    }
private:
    int gcd(int x, int y) {
     return y == 0 ? x : gcd(y, x % y);
    }
};
// @lc code=end


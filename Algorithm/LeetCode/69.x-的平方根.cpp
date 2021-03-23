/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        long long l = 1, r = x;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return (int)l;
    }
};
// @lc code=end


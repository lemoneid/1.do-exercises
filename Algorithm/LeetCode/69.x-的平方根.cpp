/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int a) {
        if (a <= 0) return 0;
        long x = a;
        while (x * x > a) {
            x = (x + a / x) / 2;
        }
        return x;
    //  while 
       // 
       // long long l = 0, r = x;
       // while (l < r) {
       //     int mid = l + (r - l + 1) / 2;
       //     //int mid = (l + r + 1) / 2;
       //     if (mid <= x / mid) l = mid;
       //     else r = mid - 1;
       // }
       // return (int)l;
    }
};
// @lc code=end


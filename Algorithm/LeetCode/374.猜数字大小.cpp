/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n, mid;
        while (l <= r) {
            int mid = l + (r- l) / 2, res= guess(mid);
            if (res == 1) {
                l = mid + 1;
            } else if (res == -1) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return l;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int p = n, q = n;
        do {
            p = calc(p);
            q = calc(calc(q));
        } while(p != q && p != 1 && q != 1);
        if (p == 1 || q == 1) return true;
        return false;

    }
private :
    int calc(int x) {
        int ans = 0;
        while (x) {
            ans += (x % 10) * (x % 10);
            x /= 10;
        }
        return ans;
    }
};
// @lc code=end


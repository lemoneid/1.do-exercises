/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0 || primes.empty()) return false;
        if (n == 1) return 1;
        vector<int> nums(n);
        vector<int> mask(primes.size(), 0);
        nums[0] = 1;
        for (int i = 1; i < n; ++i) {
            int mmin = primes[0] * nums[mask[0]];
            for (int i = 1; i < primes.size(); ++i) {
                mmin = min(mmin, primes[i] * nums[mask[i]]);
            }
            for (int i = 0; i < primes.size(); ++i) {
                if (mmin ==  primes[i] * nums[mask[i]]) mask[i]++;
            }
            nums[i] = mmin;
        }
        return nums[n - 1];
    }
};
// @lc code=end


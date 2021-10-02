/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n + 5, true);
        int i = 3, sn = sqrt(n);
        int count = n / 2;
        while (i <= sn) {
            for (int j = i * i; j < n; j += 2 * i) {
                if (prime[j]) {
                    prime[j] = false;
                    --count;
                }
            }
            do { i += 2; } while (i <= sn && prime[i] == false);
        }
        return count;
        /*
        for (int i = 2; i < n; i++) {
            if (!prime[i]) prime[++prime[0]] = i;
            for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
                prime[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;

            }
        }
        return prime[0];
        */

    }
};
// @lc code=end


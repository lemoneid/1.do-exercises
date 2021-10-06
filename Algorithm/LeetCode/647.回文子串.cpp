/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }
    int extendSubstrings(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--, r++;
            count++;
        }
        return count;
    }
    int DP_countSubstrings(string s) {
        int ans = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int d = 0; d < n; d++) {
            for (int i = 0; i + d < n; i++) {
                int j = i + d;
                if (s[i] != s[j]) continue;
                if (d == 0 || d == 1) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j]) ans++;
            }
        }
        return ans;


    }
};
// @lc code=end


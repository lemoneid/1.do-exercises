/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mmap[256] = {0};
        int ans = 0, pre = -1;
        for (int i = 0; i < 256; ++i) mmap[i] = -1;
        vector<int> dp(s.length());
        for (int i = 0; s[i]; ++i) {
            pre = max(pre, mmap[s[i]]);
            ans = max(ans, i - pre);
            mmap[s[i]] = i;
        }
        return ans;
    }
};
// @lc code=end


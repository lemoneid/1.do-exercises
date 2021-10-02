/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mmap;
        int ans = 0;
        for (const string & word : words) {
            int mask = 0, size = word.size();
            for (const char & c : word) {
                mask |= 1 << (c - 'a');
            }
            mmap[mask] = max(mmap[mask], size);
            for (const auto & [h_mask, h_len] : mmap) {
                if (!(mask & h_mask)) {
                    ans = max(ans, size * h_len);
                }
            }
        }
        return ans;

    }
};
// @lc code=end


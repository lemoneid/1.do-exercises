/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> s_first(256, 0), t_first(256, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s_first[s[i]] != t_first[t[i]]) return false;
            s_first[s[i]] = t_first[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end


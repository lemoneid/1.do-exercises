/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string get_new_string(string &s) {
        string ns = "#";
        for (int i = 0; s[i]; i++) {
            (ns += s[i]) += "#";
        }
    }
    string longestPalindrome(string s) {
        string ns = get_new_string(s);
        int *r = new int[ns.size()], c;
        r[0] = 1, c = 0;
        for (int i = 1; i < ns.size(); i++) {
            if (i >= c + r[c]) {
                r[i] = 1;
                while (i - r[i] >= 0 && ns[i - r[i]] == ns[i + r[i]]) {
                    r[i] += 1;
                }
                c = i;
                continue;
            }
            r[i] = min(c + r[c] - i, r[2 * i - c]);
            while (i - r[i] >= 0 && ns[i - r[i]] == ns[i + r[i]]) {
                r[i] +=1;
            }
            if (i + r[i] > c + r[c]) c = i;
        }
    }
};
// @lc code=end


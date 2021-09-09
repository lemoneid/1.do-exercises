/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int i = 0; 1; i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (!strs[j][i]) return strs[j].substr(0, i);
                if (!j || strs[j][i] == strs[j - 1][i]) continue;
                return strs[j].substr(0, i);
                
            }
        }
        return "";
    }
};
// @lc code=end


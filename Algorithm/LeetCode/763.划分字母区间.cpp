/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        if (s.empty()) return {0};
        vector<int> hash(128, -1);
        vector<int> ans;
        for (int i = 0; s[i]; ++i) {
            hash[s[i]] = i;
        }
        int left = 0, right = 0;
        for (int i = 1; s[i]; ++i) {
            right = max(hash[s[i]], right);
            if (i == right) {
                ans.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return ans;
        
    }
};
// @lc code=end


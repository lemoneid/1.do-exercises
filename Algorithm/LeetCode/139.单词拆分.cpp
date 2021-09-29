/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (wordSet.find(s.substr(j, i - j)) != wordSet.end() && dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }

        }
        return dp[s.size()];
    }
};
// @lc code=end


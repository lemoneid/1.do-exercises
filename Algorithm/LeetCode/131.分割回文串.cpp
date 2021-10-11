/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> path;
    void backtracking(const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            result.push_back(path);
            return ;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i) == false) continue;
            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }

    }
    bool isPalindrome(const string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};
// @lc code=end


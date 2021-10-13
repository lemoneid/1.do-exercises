/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        s += " ";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            int index = i;
            while (i < s.size() && s[i + 1] != ' ') i++;
            arr.push_back(s.substr(s.begin() + index, i - index));
        }
        string result;
        for (int i =  arr.size() - 1; i >= 0; i--) {
            result += arr[i];
            if (i > 0) result += " ";
        }
        return result;
    }
};
// @lc code=end


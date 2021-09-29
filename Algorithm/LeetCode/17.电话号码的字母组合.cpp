/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return result;
    backtrack(digits, 0);
    return result;
  }

 private:
  const string letterMap[10] = {
      "",      // 0
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz",  // 9};
  };
  vector<string> result;
  string s;
  void backtrack(const string &digits, int start) {
    if (start == digits.size()) {
      result.push_back(s);
      return;
    }
    string letters = letterMap[digits[start] - '0'];  // 取数字对应的字符集
    for (int i = 0; i < letters.size(); i++) {
      s.push_back(letters[i]);
      backtrack(digits, start + 1);
      s.pop_back();
    }
    return;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return result;
        result.clear();
        path.clear();
        backtracking(n, n);
        return result;
    }
private:
    vector<string> result;
    string path;
    void backtracking(int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(path);
        }
        if (left > right) {
            return ;
        }
        if (left > 0) {
            path.push_back('(');
            backtracking(left - 1, right);
            path.pop_back();
        }
        if (right > 0) {
            path.push_back(')');
            backtracking(left, right - 1);
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end


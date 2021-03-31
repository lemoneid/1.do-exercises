/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    if (!matrix.size() || !matrix[0].size()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for (int i = 0; i < col; i++) dp[0][i] = matrix[0][i] == '1';
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            stack<int> s;
            for (int j = 0; j < col; j++) {
                while (!s.empty() && dp[i][s.top()] > dp[i][j]) {
                    int h = dp[i][s.top()];
                    s.pop();
                    int left = s.empty() ? -1 : s.top();
                    ans = max(ans, h * (j - left - 1));
                }
                s.push(j);
            }
            while (!s.empty()) {
                int h =dp[i][s.top()];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                ans = max(ans, h * (col - left - 1));
            }
        }
        return ans;

    }
};
// @lc code=end


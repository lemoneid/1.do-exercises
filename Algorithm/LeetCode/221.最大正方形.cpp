/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int ans = 0;
        vector<vector<int>> cnt(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!i || !j || matrix[i][j] == '0') {
                    cnt[i][j] = matrix[i][j] == '0' ? 0 : 1;
                } else {
                    cnt[i][j] = min(min(cnt[i][j - 1], cnt[i - 1][j]), cnt[i - 1][j - 1]) + 1;
                }
                ans = max(ans, cnt[i][j] * cnt[i][j]);

            }
        }
        /*
        for (int j = 0; j < col; ++j) cnt[0][j] = matrix[0][j] == '1';
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cnt[i][j] = matrix[i][j] == '1' ? cnt[i - 1][j] + 1 : 0;
            }
        }
        for (int i = 0; i < row; ++i) {
            deque<int> q;
            int l = 0;
            for (int j = 0; j < col; ++j) {
                while(!q.empty() && cnt[i][q.back()] > cnt[i][j]) q.pop_back();
                q.push_back(j);
                while (j - l >= 0 && j - l + 1 > cnt[i][q.front()]) {
                    ++l;
                    if (q.front() < l) q.pop_front();
                }
                ans = max(ans, (j - l + 1) * (j - l + 1));
            }
        }
        */
        return ans;

    }
};
// @lc code=end


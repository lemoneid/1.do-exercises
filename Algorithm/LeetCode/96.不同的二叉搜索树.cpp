/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:

    int numTrees(int n) {
        if (n < 0) return 0;
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                ans[i] += ans[j - 1] * ans[i - j];
            }
        }
        return ans[n];
    }
};
// @lc code=end


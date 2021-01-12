/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        if (!root->right && !root->left) return 0;
        int ans = 0;
        getLength(root->left, 0, ans);
        getLength(root->right, 1, ans);
        return ans;
    }
private :
    int getLength(TreeNode *root, int flag, int &ans) {
        if (!root) return 0;
        int l = getLength(root->left, 0, ans);
        int r = getLength(root->right, 1, ans);
        if (!flag) {
            ans = max(ans, max(l, r + 1));
            return r + 1;
        } else {
            ans = max(ans, max(l + 1, r));
            return l + 1;
        }
    }
};
// @lc code=end


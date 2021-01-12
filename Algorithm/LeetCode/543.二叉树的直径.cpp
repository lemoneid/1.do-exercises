/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int ans = 0;
        getHeight(root, ans);
        return ans - 1;
    }
private :
    int getHeight(TreeNode *root, int &ans) {
        if (!root) return 0;
        int l = getHeight(root->left, ans), r = getHeight(root->right, ans);
        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        int ans = helper(root);
        if (!ans) return nullptr;    
        else return root;
    }
private :
    int helper(TreeNode *root) {
        if (!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if (!l) root->left = nullptr;
        if (!r) root->right = nullptr;
        return l + r + root->val;
    }

};
// @lc code=end


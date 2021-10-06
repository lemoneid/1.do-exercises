/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
    int getDepth(TreeNode *node) {
        if (!node) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        if (!node->left && node->right) {
            return 1 + rightDepth;
        }
        if (!node->right && node->left) {
            return 1 + leftDepth;
        }
        return min(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end


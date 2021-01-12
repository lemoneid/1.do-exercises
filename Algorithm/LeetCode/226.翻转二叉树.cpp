/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            if (!cur) continue;
            TreeNode *tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            que.push(cur->left);
            que.push(cur->right);
        }
        return root;
    }
};
// @lc code=end


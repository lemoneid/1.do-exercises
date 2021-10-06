/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
private:
    TreeNode *pre;
    int result = INT_MAX;
    void traversal(TreeNode *root) {
        if (!root) return ;
        traversal(root->left);
        if (pre != nullptr) {
            result = min(result, root->val - pre->val);
        }
        pre = root;
        traversal(root->right);
        return ;
    }
};
// @lc code=end


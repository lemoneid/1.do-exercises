/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ans = root->val;
        getMaxSum(root, ans);
        return ans;
    }
private :
    int getMaxSum(TreeNode *root, int &ans) {
        if (!root) return 0;
        int l = max(0, getMaxSum(root->left, ans));
        int r = max(0, getMaxSum(root->right, ans));
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
};
// @lc code=end


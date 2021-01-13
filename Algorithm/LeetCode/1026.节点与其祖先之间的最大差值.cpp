/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        helper(root, root->val, root->val, ans);
        return ans;
    }

private :
    void helper(TreeNode *root, int lower, int upper, int &ans) {
        if (!root) return ;
        ans = max(ans, max(abs(root->val - upper), abs(root->val - lower)));
        lower = min(root->val, lower);
        upper = max(root->val, upper);
        helper(root->left, lower, upper, ans);
        helper(root->right, lower, upper, ans);
    }

};
// @lc code=end


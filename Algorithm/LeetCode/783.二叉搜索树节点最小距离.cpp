/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        int ans = 0x3f3f3f3f;
        TreeNode *pre = nullptr;
        helper(root, pre, ans);
        return ans;
    }

private :
    void helper(TreeNode *root, TreeNode *&pre, int &ans) {
        if (!root) return ;
        helper(root->left, pre, ans);
        if (pre)
            ans = min(ans, abs(root->val - pre->val));
        pre = root;
        helper(root->right, pre, ans);
    }

};
// @lc code=end


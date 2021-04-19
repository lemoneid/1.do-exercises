/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        return build(root, 0);
    }
private :
    int build(TreeNode *root, int cur) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return cur * 10 + root->val;
        }
        int ans = build(root->left, cur * 10 + root->val);
        ans += build(root->right, cur * 10 + root->val);
        return ans;
    }
};
// @lc code=end


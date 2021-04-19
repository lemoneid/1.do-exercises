/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        Node ans = calc(root);
        return max(ans.x, ans.y);
    }
private : 
    struct Node {
        int x, y;
        Node() : Node(0, 0) {}
        Node(int x, int y) : x(x), y(y) {}
    };
    Node calc(TreeNode *root) {
        if (!root) return Node(0, 0);
        Node l = calc(root->left);
        Node r = calc(root->right);
        int x = root->val + l.y + r.y;
        int y = max(l.x, l.y) + max(r.x , r.y);
        return Node(x, y);
    }
};
// @lc code=end


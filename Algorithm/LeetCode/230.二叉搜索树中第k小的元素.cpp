/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        TreeNode *cur = root, *mostRight = nullptr;
        int cnt = 0, ans = 0;
        while (cur) {
            mostRight = cur->left;
            if (mostRight) {
                while (mostRight->right && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                }
            }
            if (++cnt == k) ans = cur->val;
           // cout << cur->val << " ";
            cur = cur->right;
        }
        return ans;
    }
};
// @lc code=end


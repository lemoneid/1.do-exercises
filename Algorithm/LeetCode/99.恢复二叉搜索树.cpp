/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        if (!root || !(root->left) && !(root->right)) return ;
        TreeNode *pre = nullptr, *x = nullptr, *y = nullptr, *mostRight = nullptr;
        /*
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pre && root->val < pre->val) {
                y = root;
                if (!x) x = pre;
                else break;
            }
            pre = root;
            root = root->right;
        }
        swap(x->val, y->val);
        */
        while (root) {
            if (root->left) {
                mostRight = root->left;
                while (mostRight->right && mostRight->right != root) {
                    mostRight = mostRight->right;
                }
                if (!mostRight->right) {
                    mostRight->right = root;
                    root = root->left;
                } else {
                    if (pre && pre->val > root->val) {
                        y = root;
                        if (!x) x = pre;
                    }
                    mostRight->right = nullptr;
                    pre = root;
                    root = root->right;
                }
            } else {
                if (pre && pre->val > root->val) {
                    y = root;
                    if (!x) x = pre;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
        return ;
    }

};
// @lc code=end


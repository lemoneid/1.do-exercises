/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return CreateTree(inorder, postorder, 0, inorder.size(), 0, postorder.size()); 
    }

    TreeNode* CreateTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if (is >= ie) return nullptr;
        int val = postorder[pe - 1], idx;
        TreeNode *node = new TreeNode(val);
        for (idx = is; idx < ie; ++idx) {
            if (inorder[idx] - val) continue;
            break;
        }
        node->left = CreateTree(inorder, postorder, is, idx, ps, ps + idx - is);
        node->right = CreateTree(inorder, postorder, idx + 1, ie, ps + idx - is, pe - 1);
        return node;
    }
};
// @lc code=end


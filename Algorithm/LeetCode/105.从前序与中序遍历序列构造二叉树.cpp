/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
        return root;
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2) {
        if (l1 >= r1) return nullptr;
        //if (l1 - r1 == 1) return new TreeNode(preorder[l1]);
        TreeNode *p = new TreeNode(preorder[l1]);
        int idx = l2;
        for (idx = l2; idx < r2; ++idx) {
            if (inorder[idx] - preorder[l1]) continue;
            break;
        }
        //printf("%d-%d  %d-%d\n",l1 + 1, l1 + 1 + idx - l2, l2, idx);
        //printf("%d-%d  %d-%d\n", l1 + idx - l2 + 2, r1, idx + 1, r2);
        p->left = build(preorder, inorder, l1 + 1, l1 + 1 + idx - l2, l2, idx);
        p->right = build(preorder, inorder, l1 + 1 + idx - l2, r1, idx + 1, r2);
        return p;
    }
};
// @lc code=end


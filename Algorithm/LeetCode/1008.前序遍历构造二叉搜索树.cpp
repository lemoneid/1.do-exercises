/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (!preorder.size()) return nullptr;
        return build(preorder, 0, preorder.size() - 1);
    }
    TreeNode *build(vector<int> &arr, int l, int r) {
        if (l == r) return new TreeNode(arr[l]);
        if (l > r) return nullptr;
        TreeNode *root = new TreeNode(arr[l]);
        int ind = l + 1;
        while (ind <= r && arr[ind] < arr[l]) {
            ind++;
        }
        root->left = build(arr, l + 1, ind - 1);
        root->right = build(arr, ind, r);
        return root;
    }
};
// @lc code=end


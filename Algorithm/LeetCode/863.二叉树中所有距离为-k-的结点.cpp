/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root) return arr;
        dfs(root, target, nullptr);
        collect(target, 0, K);
        collect(parent, 0, K - 1);
        return arr;
    }
private :
    vector<int> arr;
    TreeNode *parent = nullptr;
    bool dfs(TreeNode *root, TreeNode *target, TreeNode *father) {
        if (!root) return false;
        if (root == target) {
            parent = father;
            return true;
        } 
        if (dfs(root->left, target, root)) {
            root->left = father;
            return true;
        } 
        if (dfs(root->right, target, root)) {
            root->right = father;
            return true;
        }
        return false;
        
    }
    void collect(TreeNode *root, int n, int k) {
        if (!root) return ;
        if (n == k) arr.push_back(root->val);
        else {
            collect(root->left, n + 1, k);
            collect(root->right, n + 1, k);
        }
        return ;
    }
};
// @lc code=end


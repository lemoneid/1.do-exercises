/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        idx = 0;
        res.clear();
        if (dfs(root, voyage)) {
            return res;
        }
        return vector<int>{-1};

    }
private :
    int idx = 0;
    vector<int> res;
    bool dfs(TreeNode *root, vector<int> &voyage) {
        if (!root || idx > voyage.size()) return true;
        if (root->val != voyage[idx]) return false;
        idx++;
        if (root->left && root->left->val != voyage[idx]) {
            res.push_back(root->val);
            return dfs(root->right, voyage) && dfs(root->left, voyage);
        } else {
            return dfs(root->left, voyage) && dfs(root->right, voyage);
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        result.clear();
        maxLen = curLen = 0;
        traverse(root);
        return result;
    }
private:
    vector<int> result;
    int maxLen, curLen;
    TreeNode *pre = nullptr;
    void traverse(TreeNode *root) {
        if (!root)  return ;
        traverse(root->left);
        if (pre == nullptr) {
            curLen = 1;
        } else if (pre->val == root->val) {
            curLen++;
        } else {
            curLen = 1;
        }
        pre = root;
        if (curLen == maxLen) {
            result.push_back(root->val);
        } else if (curLen > maxLen) {
            result.clear();
            result.push_back(root->val);
            maxLen = curLen;
        }
        traverse(root->right);
    }
};
// @lc code=end


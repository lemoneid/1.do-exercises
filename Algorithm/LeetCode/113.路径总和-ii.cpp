/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        findPath(root, sum, path, ans);
        return ans;
    }
private :
    void findPath(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &ans) {
        if (!root) return ;
        sum -= root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && !sum) {
            ans.push_back(path);
        }
        findPath(root->left, sum, path, ans);
        findPath(root->right, sum, path, ans);
        path.pop_back();
        return ;

    }

};
// @lc code=end


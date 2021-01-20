/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;    
        vector<vector<int> > ans;
        if (!root) return ans;
        vector<int> arr;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (!cur) {
                ans.push_back(arr);
                arr.resize(0);
                if (q.size()) q.push(nullptr);
            } else {
                arr.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};
// @lc code=end


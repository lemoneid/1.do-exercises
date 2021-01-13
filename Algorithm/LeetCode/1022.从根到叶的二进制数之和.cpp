/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        stack<pair<TreeNode*, int> > stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            auto cur = stk.top();
            stk.pop();
            TreeNode *node = cur.first;
            int val = cur.second;
            val = val * 2 + node->val;

            if (!node->left && !node->right) {
                ans += val;
            }
            
            if (node->left) stk.push({node->left, val});
            if (node->right) stk.push({node->right, val});
        }
        return ans;
    }
private :
    int pathHelper(TreeNode *root, int cur) {
        if (!root) return 0;
        cur = cur << 1 | root->val;
        if (!root->left && !root->right) return cur;
        return pathHelper(root->left, cur) + pathHelper(root->right, cur);
    }
};
// @lc code=end


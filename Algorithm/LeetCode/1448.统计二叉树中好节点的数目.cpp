/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        stack<pair<TreeNode *, int> > stk;
        stk.push({root, root->val});
        while (!stk.empty()) {
            auto temp = stk.top();
            stk.pop();
            TreeNode *cur = temp.first;
            int mmax = temp.second;
            if (cur->val >= mmax) ans += 1, mmax = cur->val;
            if (cur->left) stk.push({cur->left, mmax});
            if (cur->right) stk.push({cur->right, mmax});
        }
        return ans;
    }
private :
    void helper(TreeNode *root, int mmax, int &ans) {
        if (!root) return ;
        if (root->val >= mmax) mmax = root->val, ans += 1;
        helper(root->left, mmax, ans);
        helper(root->right, mmax, ans);
        return ;
    }
};
// @lc code=end


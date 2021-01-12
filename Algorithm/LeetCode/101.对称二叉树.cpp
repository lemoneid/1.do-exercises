/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        //return helper(root->left, root->right);
        queue<PII> que;
        que.push(PII(root->left, root->right));
        while (!que.empty()) {
            PII tmp = que.front();
            que.pop();
            if (!tmp.first && !tmp.second) continue;
            if (!tmp.first || !tmp.second) return false;
            if (tmp.first->val - tmp.second->val) return false;
            que.push(PII(tmp.first->left, tmp.second->right));
            que.push(PII(tmp.first->right, tmp.second->left));
        }
        return true;
    }
private :
    typedef pair<TreeNode* , TreeNode *> PII;
    bool helper(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val - q->val) return false;
        return helper(p->left, q->right) && helper(p->right, q->left);
    }
};
// @lc code=end


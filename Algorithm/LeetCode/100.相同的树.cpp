/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val - q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        */
        queue<PII> que;
        que.push(PII(p, q));
        while (!que.empty()) {
            PII cur=  que.front();
            que.pop();
            if (!cur.first && !cur.second) continue;
            if (!cur.first || !cur.second) return false;
            if (cur.first->val - cur.second->val) return false;
            que.push(PII(cur.first->left, cur.second->left));
            que.push(PII(cur.first->right, cur.second->right));
        }
        return true;
    }
private :
    typedef pair<TreeNode *, TreeNode *> PII;
};

// @lc code=end


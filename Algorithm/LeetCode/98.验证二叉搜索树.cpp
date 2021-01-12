/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        /*
        return helper(root, LONG_MIN, LONG_MAX);
        */
       /*
        stack<TreeNode *> stk;
        long long pre = (long long)INT_MIN - 1;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->val <= pre) return false;
            pre = root->val;
            root = root->right;
        }
        */
        long long pre = (long long)INT_MIN - 1;
        stack<PII> stk;
        stk.push(PII(root, false));
        while (!stk.empty()) {
            PII cur = stk.top();
            TreeNode *p = cur.first;
            stk.pop();
            if (p == nullptr) continue;
            if (cur.second == false) {
                stk.push(PII(p->right, false));
                stk.push(PII(p, true));
                stk.push(PII(p->left, false));
            } else {
                if (p->val <= pre) return false;
                pre = p->val;
            }
        }
        return true;
    }

private :
    typedef pair<TreeNode *, bool> PII;
    bool helper(TreeNode *root, long long low, long long high) {
        if (!root) return true;
        if (root->val <= low || root->val >= high) return false;
        return helper(root->left, low, root->val) && helper(root->right, root->val, high);
    }

};
// @lc code=end


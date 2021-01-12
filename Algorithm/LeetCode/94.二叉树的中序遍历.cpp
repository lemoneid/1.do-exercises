/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        arr.clear();
        if (!root) return arr;
        /*
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            arr.push_back(root->val);
            root = root->right;
        }
        */
        stack<PII> stk;
        stk.push(PII(0, root));
        while (!stk.empty()) {
            PII temp = stk.top();
            stk.pop();
            if (!temp.second) continue;
            if (temp.first == 0) {
                stk.push(PII(0, temp.second->right));
                stk.push(PII(1, temp.second));
                stk.push(PII(0, temp.second->left));
            } else {
                arr.push_back(temp.second->val);
            }
        }
        return arr;
        
    }
private :
    vector<int> arr;
    typedef pair<int, TreeNode *> PII;
};
// @lc code=end


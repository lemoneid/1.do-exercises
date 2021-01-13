/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        for (auto & s : mp) {
            res.push_back({});
            for (auto &cur : s.second) {
                res.back().push_back(cur.second);
            }
        }
        return res;
    }
private :
    vector<vector<int>> res;
    map<int, set<pair<int, int> > > mp;
    void traverse(TreeNode *root, int x, int y) {
        if (!root) return ;
        mp[x].insert({y, root->val});
        traverse(root->left, x - 1, y + 1);
        traverse(root->right, x + 1, y + 1);
    }
};
// @lc code=end


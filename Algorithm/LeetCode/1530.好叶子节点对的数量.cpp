/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
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
    int countPairs(TreeNode* root, int distance) {
        int leaf = 0;
        dfs(root, distance, leaf);
        return leaf;
    }
private :
    vector<int> dfs(TreeNode *root, const int &distance, int &leaf) {
        vector<int> dist;
        if (!root) {
            return  dist;
        }
        if (!root->left && !root->right) {
            dist.push_back(1);
            return dist;
        }
        auto l = dfs(root->left, distance, leaf);
        auto r = dfs(root->right, distance, leaf);
        for (int i = 0; i < l.size(); ++i) {
            for (int j = 0; j < r.size(); ++j) {
                if (l[i] + r[j] <= distance) {
                    leaf += 1;
                }
            }
        }
        for (auto cur : l) dist.push_back(cur + 1);
        for (auto cur : r) dist.push_back(cur + 1);
        return dist;
    }

};
// @lc code=end


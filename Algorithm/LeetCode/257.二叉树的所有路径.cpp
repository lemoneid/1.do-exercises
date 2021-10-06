/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
private :
    vector<string> result;
    vector<int> path;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;
        travresal(root);
        return result;
    }
private:
    void travresal(TreeNode *node) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string sPath;
            for (int i = 0; i < path.size(); ++i) {
                sPath += to_string(path[i]);
                if (i != path.size() - 1) sPath += "->";
            }
            result.push_back(sPath);
            return ;
        }
        if (node->left) {
            travresal(node->left);
            path.pop_back();
        }
        if (node->right) {
            travresal(node->right);
            path.pop_back();
        }
    }
};
// @lc code=end


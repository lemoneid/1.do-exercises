/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*
        dfs(root);
        while (paths.front().back() != paths.back().back()) {
            paths.front().pop_back();
            paths.back().pop_back();
        }
        return paths.front().back();
        */
       PII ans = helper(root, 0);
       return ans.first;
        
    }
private :
    typedef pair<TreeNode *, int> PII;
    PII helper(TreeNode *root, int step) {
        if (!root) return PII(root, step);
        PII l = helper(root->left, step + 1);
        PII r = helper(root->right, step + 1);
        if (l.second == r.second) return PII(root, l.second);
        else if (l.second > r.second) return l;
        else return r;
    }
    vector<vector<TreeNode *> > paths;
    vector<TreeNode *> path;
    void dfs(TreeNode *root) {
        if (!root) return ;
        path.push_back(root);
        if (paths.empty() || path.size() > paths.back().size()) {
            paths.clear();
            paths.push_back(path);
        } else if (path.size() == paths.back().size()) {
            paths.push_back(path);
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
        return ;
    }

};
// @lc code=end


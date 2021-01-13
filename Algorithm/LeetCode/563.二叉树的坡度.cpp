/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        int fsum = 0;
        helper(root, fsum);
        return fsum;
    }
private :
    int helper(TreeNode *root, int &fsum) {
        if (!root) return 0;
        int sum = root->val;
        int suml = helper(root->left, fsum), sumr = helper(root->right, fsum);
        fsum += abs(suml - sumr);
        return sum + suml + sumr;
    }

};
// @lc code=end


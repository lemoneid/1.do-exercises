/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return build(nums, 0, nums.size());
    }
private :
    TreeNode *build(vector<int> &nums, int s, int e) {
        if (s == e) return nullptr;
        if (s + 1 >= e) return new TreeNode(nums[s]);
        int idx = s;
        for (int i = s + 1; i < e; ++i) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        TreeNode *root = new TreeNode(nums[idx]);
        root->left = build(nums, s, idx);
        root->right = build(nums, idx + 1, e);
        return root;
    }
};
// @lc code=end


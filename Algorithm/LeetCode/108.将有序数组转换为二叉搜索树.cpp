/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        if (!length) return nullptr;
        if (length == 1) return new TreeNode(nums[0]);
        return build(nums, 0, length - 1);
    }
private :
    TreeNode *build(const vector<int> &nums, int l, int r) {
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        if (l > r) return nullptr;
        int idx = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[idx]);
        root->left = build(nums, l, idx - 1);
        root->right = build(nums, idx + 1, r);
        return root;
    }
};
// @lc code=end


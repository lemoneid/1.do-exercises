/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxLeftValue;
    }
private:
    int maxLeftValue, maxLen = INT_MIN;
    void traversal(TreeNode* root, int leftLen) {
        if (!root->left && !root->right) {
            if (leftLen > maxLen) {
                maxLen = leftLen;
                maxLeftValue = root->val;
            }
            return ;
        }
        if (root->left) {
            traversal(root->left, leftLen + 1);
        }
        if (root->right) {
            traversal(root->right, leftLen + 1);
        }

        return ;
    }
};
// @lc code=end


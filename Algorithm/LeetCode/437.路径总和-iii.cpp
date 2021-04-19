/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        prexMap[0] = 1;
        target = targetSum;
        handle(root, 0, cnt);
        return cnt;
    }
private :
    map<int, int> prexMap;
    int target;
    void handle(TreeNode *root, int cur_sum, int &cnt) {
        if (!root) return ;
        cur_sum += root->val;
        cnt += prexMap[cur_sum - target];
        prexMap[cur_sum]++;
        handle(root->left, cur_sum, cnt);
        handle(root->right, cur_sum, cnt);
        prexMap[cur_sum]--;
    }
};
// @lc code=end


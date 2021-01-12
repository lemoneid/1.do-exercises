/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 1;
        queue<PII> que;
        que.push(PII(root, 1));
        while (!que.empty()) {
            int size = que.size();
            ans = max(ans, int(que.back().second - que.front().second + 1));
            for (int i = 0; i < size; ++i) {
                TreeNode *p = que.front().first;
                unsigned long long pos = que.front().second;
                que.pop();
                if (p->left) que.push({p->left, 2 * pos});
                if (p->right) que.push({p->right, 2 * pos + 1});

            }
        }
        return ans;
    }
private :
    typedef pair<TreeNode *, unsigned long long> PII;
};
// @lc code=end


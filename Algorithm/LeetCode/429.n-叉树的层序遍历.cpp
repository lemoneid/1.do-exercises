/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node *>  que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0; j < node->children.size(); ++j) {
                    if (node->children[j]) que.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        ostringstream out;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (cur == nullptr) {
                out << npos;
            } else {
                out << cur->val;
            }
            out << " ";
            if (!cur) continue;
            que.push(cur->left);
            que.push(cur->right);

        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream input(data);
        vector<TreeNode *> arr;
        int val;
        while (input >> val) {
            if (val == npos) {
                arr.push_back(nullptr);
            } else {
                arr.push_back(new TreeNode(val));
            }
        }
        int pos = 1;
        for (int i = 0; pos < arr.size(); i++) {
            if (!arr[i]) continue;
            arr[i]->left = arr[pos++];
            if (pos < arr.size()) arr[i]->right = arr[pos++];
        }
        return arr[0];
    }
    const int npos = 1111;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


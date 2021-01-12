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
        queue<TreeNode *> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            TreeNode *cur = bfs.front();
            bfs.pop();
            if (cur) {
                out << cur->val << " ";
                bfs.push(cur->left);
                bfs.push(cur->right);
            } else {
                out << "null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream input(data);
        string info;
        vector<TreeNode *> res;
        while (input >> info) {
            if (info == "null") {
                res.push_back(nullptr);
            } else {
                res.push_back(new TreeNode(stoi(info)));
            }
        }
        int pos = 1;
        for (int i = 0;  pos < res.size(); ++i) {
            if (!res[i]) continue;
            res[i]->left = res[pos++];
            if (pos < res.size()) {
                res[i]->right = res[pos++];
            }
        }
        return res[0];
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


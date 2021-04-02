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
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *cur = nullptr;
        ostringstream out;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            if (cur) {
                out << cur->val << " ";
            } else {
                out << "# ";
            }
            if (!cur) continue;
            que.push(cur->left);
            que.push(cur->right);
        }
        return out.str();
    }

    TreeNode *getNode(const string &data)  {
        if (data.size() == 0) return nullptr;
        if (data[0] == '#')  return nullptr;
        int val = 0;
        for (int i = 0; data[i]; i++) {
            val = val * 10 + data[i] - '0';
        }
        return new TreeNode(val);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        vector<TreeNode*> arr;
        istringstream input(data);
        string num;
        while (input >> num) {
            if (num == "#") arr.push_back(nullptr);
            else arr.push_back(new TreeNode(stoi(num)));
        }
        int pos = 1;
        TreeNode *cur = nullptr;
        for (int i = 0; pos < arr.size(); i++) {
            cur = arr[i];
            if (!cur) continue;
            cur->left = arr[pos++];
            if (pos < arr.size()) {
                cur->right = arr[pos++];
            }
        }
        return arr[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


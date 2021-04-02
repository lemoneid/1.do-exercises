/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    const static int BASE = 30;
    struct Node {
        Node() : Node(0) {}
        Node(int num) : num(num) {
            for (int i = 0; i < 2; i++) next[i] = nullptr;
        };
        int num;
        Node *next[2];
    };
    Node *root = new Node();
    void insert(int val) {
        Node *p = root;
        for (int i = BASE; i >= 0; i--) {
            int ind = !!((1 << i) & val);
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->num = val;
    }
    int query(int val) {
        Node *p = root;
        for (int i = BASE; i >= 0; i--) {
            int ind = !!((1 << i) & val);
            int rind = !ind;
            if (p->next[rind]) p = p->next[rind];
            else p = p->next[ind];
        }
        return p->num;
    }
    int findMaximumXOR(vector<int>& nums) {
        for (auto cur : nums) {
            insert(cur);
        }
        int ans = 0;
        for (auto cur : nums) {
            int x = query(cur);
            ans = max(ans, x ^ cur);
        }
        return ans;
    }
};
// @lc code=end


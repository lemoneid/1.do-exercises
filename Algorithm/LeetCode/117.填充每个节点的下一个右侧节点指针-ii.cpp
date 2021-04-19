/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node *start = root;
        while (start) {
            Node *pre = nullptr, *nextStart = nullptr;
            while (start) {
                if (start->left) {
                    handle(pre, start->left, nextStart);
                }
                if (start->right) {
                    handle(pre, start->right, nextStart);
                }
                start = start->next;
            }
            start = nextStart;
        }
        return root;
    }
private :
    //传引用修改原值
    void handle(Node *&pre, Node *p, Node *&nextStart) {
        if (pre) {
            pre->next = p;
        }
        pre = p;
        if (!nextStart) {
            nextStart = p;
        }
    }
};
// @lc code=end


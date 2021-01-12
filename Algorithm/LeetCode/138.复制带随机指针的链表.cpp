/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node *, Node *> node_map;
        Node *p = head, *pre = nullptr;
        while (p) {
            if (!node_map.count(p)) node_map[p] = new Node(p->val);
            if (p->random) {
                if (!node_map.count(p->random)) node_map[p->random] = new Node(p->random->val);
                node_map[p]->random = node_map[p->random];
            }
            if (pre) pre->next = node_map[p];
            pre = node_map[p];
            p = p->next;
        }
        return node_map[head];
        
    }
};
// @lc code=end


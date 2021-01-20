/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *p = head, *q = head;
        do {
            p = p->next;
            if (!q || !q->next) return nullptr;
            q = q->next->next;
        } while (p != q);
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
// @lc code=end


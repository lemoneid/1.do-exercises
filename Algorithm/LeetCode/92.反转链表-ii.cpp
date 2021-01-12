/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0), *p, *q, *tail;
        dummy->next = head;
        p = dummy;
        for (int i = 1; i < m; ++i) p = p->next;
        q = p->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode *temp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = temp;
        }
       return dummy->next; 
    }
};
// @lc code=end


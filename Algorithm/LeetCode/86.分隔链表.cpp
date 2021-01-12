/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !(head->next)) return head;
        ListNode *dummy_p = new ListNode(0);
        ListNode *dummy_q = new ListNode(0);
        ListNode *p = dummy_p, *q = dummy_q, *cur = head;
        dummy_q->next = dummy_p->next = nullptr;
        while (cur) {
            if (cur->val < x) {
                p->next = cur;
                p = cur;
            } else {
                q->next = cur;
                q = cur;
            }
            cur = cur->next;
        }
        p->next = q->next = nullptr;
        p->next = dummy_q->next;
        return dummy_p->next;
    }
};
// @lc code=end


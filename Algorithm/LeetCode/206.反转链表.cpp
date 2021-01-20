/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        /*
        ListNode dummy, *p = &dummy, *q = head, *tmp = nullptr;
        dummy.next = head;
        while (q->next) {
            tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = tmp;
        }
        return dummy.next;
        */
       ListNode *p = reverseList(head->next);
       head->next->next = head;
       head->next = nullptr;
       return p;
    }
};
// @lc code=end


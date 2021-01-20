/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode dummy, *p = &dummy, *q = head;
        dummy.next = head;
        while (q && q->next) {
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            p = q;
            q = q->next;
        }
        return dummy.next;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        /*
        int cntA = 0, cntB = 0;
        while (p) p = p->next, cntA++;
        while (q) q = q->next, cntB++;
        int sub = abs(cntA - cntB);

        p = headA, q = headB;
        if (cntA < cntB) swap(p, q);
        while (sub--) {
            p = p->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        */
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
// @lc code=end


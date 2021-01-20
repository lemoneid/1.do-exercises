/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p = head, *q = head;
        do {
            p = p->next;
            q = q->next;
            if (!q || !q->next) return false;
            q = q->next->next;

        } while(p != q);
        return true;
    }
};
// @lc code=end


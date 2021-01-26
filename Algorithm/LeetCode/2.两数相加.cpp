/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode *head = reverse(l1), *p1 = head;
        //ListNode *p2 = reverse(l2);
        ListNode *head = l1, *p1 = head, *p2 = l2;
        int pre = 0;
        while (p2 || pre) {
            if (p2) {
                p1->val += p2->val;
                p2 = p2->next;
            }
            p1->val += pre;
            pre = p1->val / 10;
            p1->val %= 10;
            if ((pre || p2) && !p1->next) p1->next = new ListNode(0);
            p1 = p1->next;
        }
        return head;
    }
private :
    ListNode *reverse(ListNode *head) {
        if (!head) return head;
        ListNode dummy, *p = &dummy, *q = head, *tmp = nullptr;
        dummy.next = head;
        while (q->next) {
            tmp = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end


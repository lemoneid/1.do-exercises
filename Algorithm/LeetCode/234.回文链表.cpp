/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *p = head, *q = head, *tag = nullptr, *pre = nullptr;
        while (q && q->next) {
            pre = p;
            p = p->next;
            q = q->next->next;
        }
        pre = q ? p : pre;
        p  = head, q = reverse(pre->next);
        while(q) {
            if (p->val - q->val) return false;
            p = p->next;
            q = q->next;
        } 
        pre->next = reverse(pre->next);
        return true;
    }
private :
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode dummy, *p = head;
        dummy.next = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end


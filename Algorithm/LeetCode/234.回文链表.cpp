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
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //od : slow 在前半
        slow->next = reverse(slow->next);
        ListNode *p = head, *q = slow->next;
        while (q) {
            if (p->val - q->val) return false;
            p = p->next;
            q = q->next;
        }
        slow->next = reverse(slow->next);
        return true;
    }
private :
    ListNode *reverse(ListNode *head) {
        ListNode *p = new ListNode(0);
        p->next = nullptr;
        while (head) {
            ListNode *tmp = head->next;
            head->next = p->next;
            p->next = head;
            head = tmp;
        }
        return p->next;
    }
};
// @lc code=end


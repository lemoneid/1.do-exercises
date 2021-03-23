/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = new ListNode(0), *h1 = p;
        ListNode *q = new ListNode(0), *h2 = q;
        int cnt = 1;
        while (head) {
            if (cnt & 1) p->next = head, p = p->next;
            else q->next = head, q = q->next;
            head = head->next;
            cnt++;
        }
        p->next = h2->next;
        q->next = nullptr;
        return h1->next;
        
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (!head || !(head->next)) return ;
        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        pre = slow;
        slow = slow->next;
        while (slow && slow->next) {
            ListNode *temp = pre->next;
            pre->next = slow->next;
            slow->next = slow->next->next;
            pre->next->next = temp;
            
        }
        slow = pre->next;
        pre->next = nullptr;
        pre = head;
        while (slow) {
            ListNode *temp = slow->next;
            slow->next = pre->next;
            pre->next = slow;
            slow = temp;
            pre = pre->next->next;
        }
        return ;
    }
};
// @lc code=end


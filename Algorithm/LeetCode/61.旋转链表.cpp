/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        k = k % len; 
        if (k == 0) return head;
        ListNode *cur = head, *pre = head, *ans = nullptr;
        for (int i = len - k - 1; i ; i--) {
            pre = pre->next;
        }
        ans = cur = pre->next;
        pre->next = nullptr;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = head;
        return ans;

    }

private :
    int length(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};
// @lc code=end


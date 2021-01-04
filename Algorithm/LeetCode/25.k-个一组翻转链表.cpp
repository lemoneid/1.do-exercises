/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        dummy->next = head;
        int cnt = length(head) / k;
        for (int i = 0; i < cnt; ++i) {
            for (int j = 1; j < k; ++j) {
                ListNode *temp = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = temp;

            }
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }

private :
    ListNode *dummy = new ListNode(0), *pre = dummy;
    int length(ListNode *head) {
        int len  = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
};
// @lc code=end


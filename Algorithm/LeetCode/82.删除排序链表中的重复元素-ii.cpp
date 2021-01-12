/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode *dummy = new ListNode(0), *pre, *cur;
        dummy->next = head;
        pre = dummy;
        cur = head->next;
        while (pre->next && pre->next->next) {
            if (pre->next->val != pre->next->next->val) {
                pre = pre->next;
            } else {
                cur = pre->next->next->next;
                while (cur && cur->val == pre->next->val) {
                    cur = cur->next;
                }
                pre->next = cur;
            }
        }
        return dummy->next;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0), *p = head->next;
        dummy->next = head;
        head->next = nullptr;
        while (p) {
            ListNode *pre = getTheInsert(dummy, p->val), *temp;
            temp = p->next;
            p->next = pre->next;
            pre->next = p;
            p = temp;
        }
        return dummy->next;
    }
private :
    ListNode* getTheInsert(ListNode *p, int val) {
        while (p->next) {
            if (p->next->val > val) {
                return p;
            }
            p = p->next;
        }
        return p;

}

};
// @lc code=end


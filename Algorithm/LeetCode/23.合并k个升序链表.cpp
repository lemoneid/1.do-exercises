/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    typedef pair<int, ListNode *> PII;
    struct cmp {
        bool operator()(const PII &a, const PII &b) const {
          return a.first > b.first;
      }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        //return merge(lists, 0, lists.size() - 1);
        priority_queue<PII, vector<PII>, cmp> q;
        for (auto cur : lists) {
            if (cur) q.push({cur->val, cur});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto cur = q.top();
            ListNode *ptr = cur.second;
            q.pop();
            tail->next = ptr;
            tail = tail->next;
            if (ptr->next) q.push({ptr->next->val, ptr->next});
        }
        tail->next = nullptr;
        return head.next;

    }
private :
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy, *p = &dummy;
        dummy.next = nullptr;
        while (l1 || l2) {
            if (!l2 || l1 && l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end


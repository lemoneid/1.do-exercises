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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        //return merge(lists, 0, lists.size() - 1);
        std::function<bool(const ListNode *, const ListNode *)> cmp = [](const ListNode *a, const ListNode *b)->bool {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> heap(cmp);
        for (auto cur : lists) {
            if (cur) heap.push(cur);
        }
        ListNode dummy(0), *p = &dummy;
        while (!heap.empty()) {
            auto cur = heap.top();
            heap.pop();
            p->next = cur;
            p = cur;
            if (cur->next) heap.push(cur->next);
        }
        p->next = nullptr;
        return dummy.next;

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


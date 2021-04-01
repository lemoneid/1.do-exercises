/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
class LFUCache {
public:
    struct Node {
        Node() : Node(0, 0, 0) {}
        Node(int key, int val, int times) : 
            key(key), val(val), times(times), 
            pre(nullptr), next(nullptr) {}
        int key, val, times;
        Node *pre, *next;
    };

    struct ListNode {
        ListNode() {
            head.next = &tail;
            tail.pre = &head;
        }

        void insert_tail(Node *p) {
            p->next = &tail;
            p->pre = tail.pre;
            tail.pre->next = p;
            tail.pre = p;
        }

        void remove_node(Node *p) {
            p->next->pre = p->pre;
            p->pre->next = p->next;
        }
        Node head, tail;
    };
    

    LFUCache(int capacity) {
        this->min_count = 0;
        this->cnt = 0;
        this->capacity = capacity;
    }

    void updata() {
        while (ind.find(min_count) != ind.end() && ind[min_count]->head.next == &(ind[min_count]->tail)) {
            min_count++;
        }
        if (ind.find(min_count) == ind.end()) {
            min_count = 0;
        }
    }

    void increase(Node *p) {
        ListNode *list = ind[p->times];
        list->remove_node(p);
        p->times++;
        if (ind.find(p->times) == ind.end()) {
            ind[p->times] = new ListNode();
        }
        list = ind[p->times];
        list->insert_tail(p);
        updata();
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node *p = cache[key];
        increase(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return ;
        if (cache.find(key) == cache.end()) {
            if (cnt == capacity) {
                ListNode *list = ind[min_count];
                Node *p = list->head.next;
                list->remove_node(p);
                cache.erase(p->key);
                delete p;
                cnt--;
                updata();
            }
            Node *p = new Node(key, value, 1);
            cache[key] = p;
            if (ind.find(1) == ind.end()) {
                ind[1] = new ListNode();
            }
            ListNode *list = ind[1];
            list->insert_tail(p);
            cnt++;
            min_count = 1;
        } else {
            Node *p = cache[key];
            p->val = value;
            increase(p);
        }
    }
private :
    unordered_map<int, Node *> cache;
    unordered_map<int, ListNode *> ind;
    int min_count, cnt, capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


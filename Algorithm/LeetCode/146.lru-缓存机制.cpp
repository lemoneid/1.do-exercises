/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:

    struct Node {
        Node() : Node(0, 0) {}
        Node(int key, int val) : key(key), val(val), pre(nullptr), next(nullptr) {}
        int key, val;
        Node *pre, *next;
    };

    void remove_node(Node *p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void insert_tail(Node *p) {
        p->next = tail;
        p->pre = tail->pre;
        tail->pre->next = p;
        tail->pre = p;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->cnt = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node *p = cache[key];
        remove_node(p);
        insert_tail(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            Node *p = new Node(key, value);
            cache[key] = p;
            insert_tail(p);
            cnt++;
        } else {
            Node *p = cache[key];
            p->val = value;
            remove_node(p);
            insert_tail(p);
        }
        if (cnt > capacity) {
            Node *p = head->next;
            remove_node(p);
            cache.erase(p->key);
            delete p;
            cnt--;
        }
    }
private :
    int capacity, cnt;
    unordered_map<int, Node *> cache;
    Node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


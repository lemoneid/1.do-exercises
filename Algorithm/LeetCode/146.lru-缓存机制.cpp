/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
public:
    typedef pair<int, int> PII;
    int capacity, t;
    unordered_map<int, PII> cache;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->t = 0;

    }
    
    int get(int key) {
        auto iter = cache.find(key);
        if (iter == cache.end()) return -1;
        if (t - iter->second.first > capacity) {
            cache.erase(iter);
            return -1;
        }
        iter->second.first = t++;
        return iter->second.second;
    }
    
    void put(int key, int value) {
        cache[key] = PII(t++, value);
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


/*************************************************************************
	> File Name: 460.cpp
	> Author: yanzhiwei
	> Mail: 1931248856@qq.com
	> Created Time: 2021年03月17日 星期三 19时08分06秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
struct Node {
    Node() : Node(0, 0, 0) {}
    Node(int key, int value, int cnt) : key(key), value(value), cnt(cnt) {}
    int key, value, cnt;
    Node *pre, *next;
};

struct DoubeList {
    DoubeList() {
        head.next = &tail;
        tail.pre = &head;
    }
    void remove_node(Node *p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }
    void insert_node(Node *p) {
        p->next = head.next;
        p->pre = &head;
        head.next->pre = p;
        head.next = p;
        
    }
    Node head, tail;  
};
class LFUCache {
public:
    int min, capacity, size;
    unordered_map<int , Node*> cache;
    unordered_map<int , DoubeList*> ind;
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min = 0;
        this->size = 0;
        return ;
    }

    void increase(Node *p) {
        int cnt = p->cnt;
        DoubeList *list = ind[cnt];
        list->remove_node(p);
        if (cnt == min && list->head.next == &(list->tail)) {
            min += 1;
        }
        p->cnt++;
        list = ind[cnt + 1];
        if (list == nullptr) {
            list = new DoubeList();
            ind[cnt + 1] = list;
        }
        list->insert_node(p);
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node *p = cache[key];
        increase(p);
        return p->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return ;
        Node *p =nullptr;
        if (cache.find(key) == cache.end()) {
//            cout << "func : put : " << value << endl;
            if (size == capacity) {
                DoubeList *minList = ind[min];
                cache.erase(minList->tail.pre->key);
                minList->remove_node((minList->tail).pre);
                size--;
            }
           p = new Node(key, value, 0);
           cache[key] = p;
           DoubeList *list = ind[1];
           if (list == nullptr) {
              list = new DoubeList() ;
              ind[1] = list;
           } 
           list->insert_node(p);
           size++;
           min = 1;
        } else {
            p = cache[key];
            p->cnt++;
            increase(p);
        }
    }
};

//["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]


int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
    return 0;
}

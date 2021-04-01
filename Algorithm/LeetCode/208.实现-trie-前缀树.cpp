/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    const static int BEGIN_LETTER = 'a';
    const static int MAX_N = 26;
    struct Node {
        Node() : Node(0) {}
        Node(int flag) : flag(flag) {
            for (int i = 0; i < MAX_N; i++) {
                next[i] = nullptr;
            }
        }
        int flag;
        Node *next[MAX_N];
    };
    Node *root;
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!root) return ;
        Node *cur = root;
        for (int i = 0; word[i]; i++) {
            int ind = word[i] - BEGIN_LETTER;
            if (cur->next[ind] == nullptr) cur->next[ind] = new Node();
            cur = cur->next[ind];
        }
        cur->flag = 1;
        return ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (!root) return false;
        Node *cur = root;
        for (int i = 0; word[i]; i++) {
            int ind = word[i] - BEGIN_LETTER;
            if (cur->next[ind] == nullptr) return false;
            cur = cur->next[ind];
        }
        return cur->flag == 1;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (!root) return false;
        Node *cur = root;
        for (int i = 0; prefix[i]; i++) {
            int ind = prefix[i] - BEGIN_LETTER;
            if (cur->next[ind] == nullptr) return false;
            cur = cur->next[ind];
        }
        if (cur->flag == 1) return true;
        for (int i = 0; i < MAX_N; i++) {
            if (cur->next[i]) return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


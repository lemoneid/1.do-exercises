/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
public:
    /** Initialize your data structure here. */
    const static int BEGIN_LETTER = 'a';
    const static int MAX_N = 26;
    struct Node {
        Node() : flag(0) {
            for (int i = 0; i < MAX_N; i++) {
                next[i] = nullptr;
            }
        }
        int flag;
        Node *next[MAX_N];
    };
    Node *root;
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        if (!root) return ;
        Node *p = root;
        for (int i = 0; word[i]; i++) {
            int ind = word[i] - BEGIN_LETTER;
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->flag = 1;
        return ;
    }

    bool search(string word) {
        return search(root, word, 0);
    }
    
    bool search(Node *p, string &word, int start) {
        if (!p) return false;
        for (int i = start; word[i]; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < MAX_N; j++) {
                    if (p->next[j] == nullptr) continue;
                    if (search(p->next[j], word, i + 1)) return true;
                }
                return false;
            }
            int ind = word[i] - BEGIN_LETTER;
            if (p->next[ind] == nullptr) return false;
            p = p->next[ind];
        }
        return p->flag == 1;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end


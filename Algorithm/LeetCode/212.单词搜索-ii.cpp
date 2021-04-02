/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
public:
    const static int BEGIN_LETTER = 'a';
    const static int MAXN = 26;
    struct Node {
        Node() : flag(false), word("") {
            for (int i = 0; i < MAXN; i++) next[i] = nullptr;
        }
        bool flag;
        string word;
        Node *next[MAXN];
    };

    void insert(Node *root, string &word) {
        if (!root) return;
        Node *p = root;
        for (int i = 0; word[i]; i++) {
            int ind = word[i] - BEGIN_LETTER;
            if (p->next[ind] == nullptr) p->next[ind] = new Node();
            p = p->next[ind];
        }
        p->word = word;
        p->flag = true;
    }

    Node *build(vector<string> &words) {
        Node *root = new Node();
        for (int i = 0; i < words.size(); i++) {
            insert(root, words[i]);
        }
        return root;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *root = build(words);
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, root, i, j);
                cout << endl;
            }
        }
        return ans;
    }
private :
    void dfs(vector<vector<char>> &board, Node *root, int x, int y) {
        char ch = board[x][y];
        int ind = ch - BEGIN_LETTER;
        if (ch == '#' || root->next[ind] == nullptr) return ;
        int row = board.size(), col = board[0].size();
        root = root->next[ind];
        if (root->flag) {
            ans.push_back(root->word);
            root->flag = false;
        }
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 0 || yy < 0 || xx >= row || yy >= col) continue;
            dfs(board, root, xx, yy);
        }
        board[x][y] = ch;
        return ;
    }
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    vector<string> ans;

};
// @lc code=end


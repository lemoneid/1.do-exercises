/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class UnionSet {
public :
    vector<int> fa;
    void init(int n) {
        fa.clear();
        for (int i = 0; i <= n; ++i) {
            fa.push_back(i);
        }
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    bool merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return false;
        fa[aa] = bb;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        u.init(edges.size() * 2);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            if (!u.merge(a, b)) {
                res.clear();
                res.push_back(a);
                res.push_back(b);
            }
        }
        return res;

    }
private :
    UnionSet u;
};
// @lc code=end


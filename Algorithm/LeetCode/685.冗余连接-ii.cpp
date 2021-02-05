/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int indeg[N] = {0};
        n = edges.size();
        for (int i = 0; i < n; ++i) {
            indeg[edges[i][1]]++;
        }
        vector<int> arr;
        for (int i = n - 1; i >= 0; i--) {
            if (indeg[edges[i][1]] == 2) {
                arr.push_back(i);
            }
        }
        if (arr.size()) {
            if (isTree(edges, arr[0])) {
                return edges[arr[0]];
            } else {
                return edges[arr[1]];
            }
        }
        return getRemoveEdge(edges);
    }
private :
    static const int N = 1010;
    int father[N];
    int n;
    void init() {
        for (int i = 1; i <= n; ++i) father[i] = i;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    bool merge(int u, int v) {
        int fu = get(u), fv = get(v);
        if (fu == fv) return false;
        father[fu] = fv;
        return true;
    } 
    vector<int> getRemoveEdge(const vector<vector<int>> &edges) {
        init();
        for (int i = 0; i < n; ++i) {
            if (!merge(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return {};
    }
    bool isTree(const vector<vector<int>> &edges, int delEdge) {
        init();
        for (int i = 0; i < n; ++i) {
            if (i == delEdge) continue;
            if (!merge(edges[i][0], edges[i][1])) {
                return false;
            }
        }
        return true;
    }

};
// @lc code=end


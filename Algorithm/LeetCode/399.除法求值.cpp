/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class UnionSet {
public :
    vector<int> fa;
    vector<double> val;
    void init(int n) {
        fa.clear();
        val.clear();
        for (int i = 0; i <= n; ++i) {
            fa.push_back(i);
            val.push_back(1);
        }
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] *= val[fa[x]];
        return fa[x] = root;
    }
    int merge(int u, int v, double z) {
        int fu = get(u), fv = get(v);
        if (fu == fv) return false;
        fa[fu] = fv;
        val[fu] = z * val[v] / val[u];
        return true;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        cnt = 0;
        for (int i = 0; i < equations.size(); ++i) {
            for (int j = 0; j < 2; ++j) {
                if (ind.find(equations[i][j]) != ind.end()) continue;
                ind[equations[i][j]] = ++cnt;
            }
        }
        //cout << cnt << endl;
        u.init(cnt);
        for (int i = 0; i < equations.size(); ++i) {
            u.merge(ind[equations[i][0]], ind[equations[i][1]], values[i]);
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); ++i) {
            int x = ind.find(queries[i][0]) == ind.end() ? 0 : ind[queries[i][0]];
            int y = ind.find(queries[i][1]) == ind.end() ? 0 : ind[queries[i][1]];
            if (!x || !y || u.get(x) != u.get(y)) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(u.val[x] * 1.0 / u.val[y]);
        }
        return res;
    }
private :
    UnionSet u;
    unordered_map<string, int> ind;
    int cnt;
};

// @lc code=end


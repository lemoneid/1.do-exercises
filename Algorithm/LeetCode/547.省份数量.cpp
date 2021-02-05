/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
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
    void merge(int a, int b) {
        fa[get(a)] = get(b); 
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        u.init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!isConnected[i][j]) continue;
                u.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (u.get(i) == i) ans++;
        }
        return ans;
    }
private :
    UnionSet u;
};
// @lc code=end


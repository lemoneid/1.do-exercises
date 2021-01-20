/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return false;
        if (n == 1) return 1;
        priority_queue<long long, vector<long long>, greater<long long> > q;
        set<long long> s;
        q.push(1);
        s.insert(1);
        vector<long long> mask({2, 3, 5});
        for (long long i = 1; i < n; ++i) {
            long long cur = q.top();
            q.pop();
            for (auto num : mask) {
                if (!s.count(cur * num)) {
                    s.insert(cur * num);
                    q.push(cur * num);
                }
            }
        }
        return q.top();
        /*
        int t1 = 0, t2 = 0, t3 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i = 1; i < n; ++i) {
            int f1 = k[t1] * 2, f2 = k[t2] * 3, f3 = k[t3] * 5;
            k[i] = min(f1, min(f2, f3));
            if (k[i] == f1) t1++;
            if (k[i] == f2) t2++;
            if (k[i] == f3) t3++;
        }
        return k[n - 1];
        */
    }
};
// @lc code=end


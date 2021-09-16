/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

class UnionSet {
public:
    vector<int> size, father;
    void init(int n) {
        father.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            father[i] = i;
            size[i] = 1;
        }
        return ;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        int fa = get(a), fb = get(b);
        if (fa == fb) return;
        father[fa] = fb;
        size[fb] += size[fa];
        return ;
    }

};
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> s;
        u.init(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (s.find(val) != s.end()) continue;
            if (s.find(val - 1) != s.end()) {
                u.merge(s[val - 1], i);
            }
            if (s.find(val + 1) != s.end()) {
                u.merge(s[val + 1], i);
            }
            s[val] = i;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, u.size[i]);
        }
        return ans;
    }
private : 
    UnionSet u;

};
// @lc code=end

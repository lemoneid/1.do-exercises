/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class UnionSet
{
public:
    vector<int> fa, size;
    void init(int n)
    {
        for (int i = 0; i <= n; ++i)
        {
            fa.push_back(i);
            size.push_back(1);
        }
    }
    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b)
    {
        int aa = get(a), bb = get(b);
        if (aa == bb)
            return;
        fa[aa] = bb;
        size[bb] += size[aa];
        return;
    }
};
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        /*
        int maxCount = 0, lCount = 0, rCount = 0;
        unordered_map<int, int> s;
        for (auto nums[i] : nums) {
            if (s[nums[i]]) continue;
            int l = s[nums[i] - 1], r = s[nums[i] + 1];
            int sum = l + r + 1;
            s[nums[i]] = s[nums[i] - l] = s[nums[i] + r] = sum;
            maxCount = max(maxCount, sum);
        }
        return maxCount;
        */
        /*
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        for (auto nums[i] : nums) {
            if (!set.count(nums[i])) continue;
            set.erase(nums[i]); 
            int pre = nums[i] - 1, next = nums[i] + 1;
            while (set.count(pre)) set.erase(pre--);
            while (set.count(next)) set.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
        */

        unordered_map<int, int> s;
        u.init(nums.size() + 5);
        for (int i = 0; i < nums.size(); ++i)
        {
            int k = nums[i];
            if (s.find(k) != s.end())
                continue;
            if (s.find(k - 1) != s.end())
            {
                u.merge(i, s[k - 1]);
            }
            if (s.find(k + 1) != s.end())
            {
                u.merge(i, s[k + 1]);
            }
            s[k] = i;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            ans = max(ans, u.size[nums[i]]);
        }
        return ans;
    }

private:
    UnionSet u;
};
// @lc code=end

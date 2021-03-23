/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mmap;
        int ans = 0;
        for (auto cur : nums) {
            mmap[cur]++;
            if (mmap.find(cur - 1) != mmap.end()) {
                ans = max(ans, mmap[cur] + mmap[cur - 1]);
            }
            if (mmap.find(cur + 1) != mmap.end()) {
                ans = max(ans, mmap[cur] + mmap[cur + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end


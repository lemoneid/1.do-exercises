/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            if (a[0] - b[0]) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i + 1 < intervals.size() && intervals[i + 1][0] <= end) end = max(end, intervals[++i][1]);
            ans.push_back({start, end});
        }
        return ans;
    }
};
// @lc code=end


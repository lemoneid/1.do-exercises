/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size < 2) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });   
        int total = 0, prev = intervals[0][1];
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] < prev) {
                ++total; 
            } else {
                prev = intervals[i][1];
            }
        }
        return total;
    }
};

// @lc code=end


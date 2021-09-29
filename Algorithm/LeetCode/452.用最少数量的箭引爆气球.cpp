/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        int size = points.size();
        sort(points.begin(), points.end(), cmp);
        int ans = 1, right = points[0][1];
        for (int i = 1; i < size; i++) {
            if (points[i][0] > right) {
                ans++;
                right = points[i][1];
            } else {
                right = min(points[i][1], right);
            }
        }
        return ans;

    }
private : 
static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y, cnt = 0;
        while (diff) {
            diff &= (diff - 1);
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end


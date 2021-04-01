/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), preMin = 0x3f3f3f3f, start = 0, total = 0;
        for (int i = 0; i < n; i++) {
           total += gas[i] - cost[i]; 
           if (total < preMin) {
               preMin = total;
               start = i + 1;
           }
        }
        return total >= 0 ? (start) % n : -1;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans = false;
        int a = 0, b = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                a++;
            } else if (bills[i] == 10) {
                if (a < 0) return false;
                a--;
                b++;
            } else if (bills[i] == 20){
                if (b > 0 && a > 0) {
                    b--;
                    a--;
                } else if (a >= 3) {
                    a -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end


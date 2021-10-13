/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int index = 0;
        while(index < s.size()){
            reverse(s.begin()+index, s.begin()+index+k > s.end() ? s.end() : s.begin()+index+k);
            index += 2*k;
        }
        return s;
    }
};
// @lc code=end


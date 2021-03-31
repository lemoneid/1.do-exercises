/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l < r) {
            while (l < r && A[r] & 1 == 1) r--;
            while (l < r && A[l] %  2 == 0) l++;
            if (l < r) {
                swap(A[l], A[r]);
                l++, r--;
            }
        }
        return A;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> s;
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            s[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (s[nums2[i]]) {
                res.push_back(nums2[i]);
                s[nums2[i]]--;
            }
        }
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double kth(vector<int> &n1, vector<int> &n2, int k) {
        int len1 = n1.size(), len2 = n2.size();
        int t1 = 0, t2 = 0, res = 0;
        while (true) {
            if (t1 == len1) {
                res = n2[t2 + k - 1];
                break;
            }
            if (t2 == len2) {
                res = n1[t1 + k - 1];
                break;
            }
            if (k == 1) {
                res = min(n1[t1], n2[t2]);
                break;
            }
            int idx1 = min(t1 + k / 2 - 1, len1 - 1);
            int idx2 = min(t2 + k / 2 - 1, len2 - 1);
            if (n1[idx1] <= n2[idx2]) {
                k -= idx1 - t1 + 1;
                t1 = idx1 + 1;
            } else {
                k -= idx2 - t2 + 1;
                t2 = idx2 + 1;
            }
        }
        return res;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int k = (len1 + len2) >> 1;
        double m1 = kth(nums1, nums2, k + 1);
        if ((len1 + len2) & 1 == 1) {
            return m1;
        }
        double m2 = kth(nums1, nums2, k);
        return (m1 + m2) / 2.0;
    }
};
// @lc code=end


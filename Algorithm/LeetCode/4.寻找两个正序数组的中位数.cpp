/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double getKth(vector<int> &n1, vector<int> &n2, int k) {
        int p1 = 0, p2 = 0, len1 = n1.size(), len2 = n2.size();
        while (1) {
            if (p1 == len1) return n2[p2 + k - 1];
            if (p2 == len2) return n1[p1 + k - 1];
            if (k == 1) return min(n1[p1], n2[p2]);
            int x1 = min(p1 + k / 2 - 1, len1 - 1);
            int x2 = min(p2 + k / 2 - 1, len2 - 1);
            if (n1[x1] < n2[x2]) {
                k -= x1 - p1 + 1;
                p1 = x1 + 1;
            } else {
                k -= x2 - p2 + 1;
                p2 = x2 + 1;
            }
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int mid = (len + 1) >> 1;
        double x = getKth(nums1, nums2, mid);
        if (len & 1) {
            return x;
        } else {
            double y = getKth(nums1, nums2, mid + 1);
            return (x + y) / 2;
        }
        return -1;
    }
};
// @lc code=end


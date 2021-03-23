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
        int t1 = 0, t2 = 0;
        while (1) {
            if (t1 == len1) return n2[t2 + k - 1];
            if (t2 == len2) return n1[t1 + k - 1];
            if (k == 1) return min(n1[t1], n2[t2]);
            int p1 = min(t1 + k / 2 - 1, len1 - 1);
            int p2 = min(t2 + k / 2 - 1, len2 - 1);
            if (n1[p1] < n2[p2]) {
                k -= p1 - t1 + 1;
                t1 = p1 + 1;
            } else {
                k -= p2 - t2 + 1;
                t2 = p2 + 1;
            }
        }            
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int sum = len1 + len2;
        double x = kth(nums1, nums2, sum / 2 + 1);
        if (sum & 1) return x; 
        double y = kth(nums1, nums2, sum / 2);
        return (x + y) / 2;
    }
};
// @lc code=end


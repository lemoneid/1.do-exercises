/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int size = nums.size();
        vector<int> arr(size + 5, 0);
        int head = 0, tail = -1;
        for (int i = 0; i < size; ++i) {
            if (head == tail + 1 || nums[i] <= arr[tail]) {
                arr[++tail] = nums[i];
            } else {
                arr[getIndex(arr, 0, tail, nums[i])] = nums[i];
            }
        }
        return tail - head + 1;
    }
    int getIndex(vector<int> &arr, int l, int r, int val) {
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (arr[mid] >= val) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
// @lc code=end


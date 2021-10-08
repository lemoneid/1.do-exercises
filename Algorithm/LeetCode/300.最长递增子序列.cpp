/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return 1;
        int size = nums.size();
        vector<int> arr(size + 5, 0);
        int head = 0, tail = -1;
        for (int i = 0; i < size; i++) {
            if (tail + 1 == head || arr[tail] < nums[i]) {
                arr[++tail] = nums[i];
            } else {
                arr[getIdx(arr, 0, tail, nums[i])] = nums[i];
            }
        }
        return tail - head + 1;
    }
    int getIdx(vector<int> &arr, int l, int r, int k) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return getKth(nums, 0, nums.size() - 1, nums.size() - k);
    }
    int getKth(vector<int> &arr, int l, int r, int idx) {
        int x = partition(arr, l, r);
        if (x == idx) return arr[x];
        return x < idx ? getKth(arr, x + 1, r, idx) : getKth(arr, l, x - 1, idx);
    }

    int partition(vector<int> &arr, int l, int r) {
        int ind = rand() % (r - l + 1) + l;
        swap(arr[ind], arr[l]);
        int val = arr[l];
        int x = l, y = r;
        while (x < y) {
            while (x < y && arr[y] >= val) y--;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= val) x++;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = val;
        return x;
    }
};
// @lc code=end


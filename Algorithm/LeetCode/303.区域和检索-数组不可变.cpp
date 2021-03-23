/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = nums[i] + sum[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        int pre = left == 0 ? 0 : sum[left - 1];
        return sum[right] - pre;
    }
private :
    vector<long long> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end


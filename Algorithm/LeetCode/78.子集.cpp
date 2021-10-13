/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        result.resize(1 << size);
        for (int i = 0, I = 1 << size; i < I; i++) {
            for (int j = 0; j < size; j++) {
                if ((i  >> j) & 1) {
                    result[i].push_back(nums[j]);
                }
            }
        }
        return result;
        //result.clear();
        //path.clear();
        //backtracking(nums, 0);
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int start) {
        result.push_back(path);
        if (start > nums.size()) return ;
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return ;
    }
};
// @lc code=end


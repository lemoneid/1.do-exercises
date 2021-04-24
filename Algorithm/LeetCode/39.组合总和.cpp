/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> arr;
        handle(candidates, 0, 0, target, arr);
        return ans;
    }
    void handle(vector<int>& cand, int start, int cur_sum, int target, vector<int> &arr) {
        if (cur_sum > target) return ;
        if (cur_sum == target) {
            ans.push_back(arr);
            return ;
        }
        for (int i = start; i < cand.size(); i++) {
            cur_sum += cand[i];
            arr.push_back(cand[i]);
            handle(cand, i, cur_sum, target, arr);
            cur_sum -= cand[i];
            arr.pop_back();
        }
    }
    vector<vector<int>> ans;
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        k += 1;
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s[nums[i]]++;
            if (i >= k) s[nums[i - k]]--;
            if (s[nums[i]] == 2) return true;
        }
        */
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end


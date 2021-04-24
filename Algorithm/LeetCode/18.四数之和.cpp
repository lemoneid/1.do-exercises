/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= len - 4; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j <= len - 3; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = len - 1;
                if ((nums[i] + nums[j]) * 2 > target) break;
                while (l < r) {
                    int sum = nums[l] + nums[r] + nums[i] + nums[j];
                    if (sum == target) {
                        cout << sum << endl;
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end


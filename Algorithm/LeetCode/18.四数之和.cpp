/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());

        unordered_map<int, pair<int, int>> cache;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                //cache[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
                cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int key = target - nums[i] - nums[j];
                const auto& vec = cache[key];
                for (int k = 0; k < vec.size(); ++k) {
                    if (i <= vec[k].second) {
                        continue; // 重叠
                    }
                    res.push_back({nums[vec[k].first], nums[vec[k].second], nums[i], nums[j]});
                }
            }
        }
        return res;





        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) continue; //nums[i]变
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; //nums[j]变
                int a = j + 1, b = nums.size() - 1;
                while (a < b) {
                    if (nums[a] + nums[b] - target == -(nums[i] + nums[j])) {
                        cout << nums[i] << " " << nums[j] << " " << nums[a] << " " << nums[b] << endl;
                        res.push_back({nums[i], nums[j], nums[a], nums[b]});
                        ++a;
                        --b;
                        while (a < b && nums[a] == nums[a - 1]) ++a;
                        while (a < b && nums[b] == nums[b + 1]) --b;
                    } else if (nums[a] + nums[b] - target < -(nums[i] + nums[j])) {
                        ++a;
                    } else {
                        --b;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end


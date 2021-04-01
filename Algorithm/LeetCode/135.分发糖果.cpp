/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 0);
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                arr[i] = arr[i - 1] + 1;
                continue;
            }
            
            if (ratings[i] < ratings[i - 1] && arr[i - 1] == 1) {
                for (int j = 0; j < i; j++) {
                    arr[j] += 1;
                }
            }
            arr[i] = 1; 
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += arr[i];
        }
        return ans;
    }
};
// @lc code=end


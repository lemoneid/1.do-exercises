/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int maxPos = 0;
        int steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end) {
                end = maxPos;
                steps++;
            }
        }
        return steps;
    }
    struct Node {
        int ind, step;
    };
    int jump_1(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<bool> check(n, false);
        queue<Node> que;
        que.push({0, 0});
        check[0] = true;
        while (!que.empty()) {
            auto cur = que.front();
            int ind = cur.ind;
            que.pop();
            if (cur.ind + nums[cur.ind] >= n - 1) {
                return cur.step + 1;
            }
            for (int i = 1; i <= nums[cur.ind]; i++) {
                if (check[ind + i]) continue;
                check[ind + i] = true;
                que.push({ind + i, cur.step + 1});
            }
        }
        return -1;
    }
};
// @lc code=end


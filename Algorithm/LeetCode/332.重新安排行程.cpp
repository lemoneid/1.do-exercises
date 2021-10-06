/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        vector<string> ans;
        if (tickets.empty()) return ans;
        unordered_map<string, multiset<string>> hash;
        for (const auto &ticket : tickets) {
            hash[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFX");
        while (!s.empty()) {
            string next = s.top();
            if (hash[next].empty()) {
                ans.push_back(next);
                s.pop();
            } else {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


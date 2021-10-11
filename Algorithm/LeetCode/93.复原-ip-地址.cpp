/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() > 12) return result;  // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
private:
    vector<string> result;
    void backtracking(string &s, int start, int k) {
        if (k == 3) {
            if (isValid(s, start, s.size() - 1)) {
                result.push_back(s);
            }
            return ;
        }
        for (int i = start; i < s.size(); i++) {
            if (!isValid(s, start, i)) break;
            s.insert(s.begin() + i + 1, '.');
            backtracking(s, i + 2, k + 1);
            s.erase(s.begin() + i + 1);
        }
    }
    bool isValid(const string &s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') return false;
            num = num * 10 + s[i] - '0';
        }
        if (num > 255) return false;
        return true;
    }

};
// @lc code=end


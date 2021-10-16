/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int result = 0;
        int i = 0, j = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        while (i < len1 && j < len2) {
            int a = getValue(version1, i); 
            int b = getValue(version2, j);
            if (a == b) continue;
            if (a < b) return -1;
            else return 1;
        }
        if (i >= len1 && j >= len2) {
            return 0;
        }
        while (i < len1) {
            if (getValue(version1, i) != 0) return 1;
        }
        while (j < len2) {
            if (getValue(version2, j) != 0) return -1;
        }
        return 0;
    }
private:
    int getValue(const string &s, int &ind) {
        int val = 0;
        while (ind < s.size() && s[ind] != '.') {
            val = val * 10 + s[ind] - '0';
            ind++;
        }
        ind++;
        return val;
    }
};
// @lc code=end


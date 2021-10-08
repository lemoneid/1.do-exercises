/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) {
            return false;
        } 
        int size = pushed.size();
        int j = 0;
        stack<int> s;
        for (int i = 0; i < size; i++) {
            s.push(pushed[i]);
            while (!s.empty() && j < size && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return j == size;
    }
};
// @lc code=end


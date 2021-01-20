/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto n : nums) {
            q.push(n);
        }
        while (q.size() > k) q.pop();
    }
    
    int add(int val) {
        q.push(val);
        if  (q.size() > k) q.pop();
        return q.top();
    }
private :
    int k;
    priority_queue<int, vector<int>, greater<int> > q;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end


class Solution {
    private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同⼀树⽀candidates[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层candidates[i - 1]使⽤过
            // 要对同⼀树层使⽤过的元素进⾏跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这⾥是i+1，每个数字在每个组合中只能使⽤⼀次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {vector<bool> used(candidates.size(), false);
                                                                            path.clear();
                                                                              result.clear();
                                                                              // ⾸先把给candidates排序，让其相同的元素都挨在⼀起。
                                                                              sort(candidates.begin(), candidates.end());
                                                                              backtracking(candidates, target, 0, 0, used);
                                                                              return result;
                                                                             }
};

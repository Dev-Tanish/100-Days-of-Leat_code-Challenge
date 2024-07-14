class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(result, current, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& candidates, int target, int start)
    {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            backtrack(result, current, candidates, target - candidates[i], i + 1);
            current.pop_back();
        }
    }
};
// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ret;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int i, int sum) {
            if(sum > target) return;
            if(sum == target) {
                ret.push_back(path);
                return;
            }

            for(int j = i; j < n; ++j) {
                path.push_back(candidates[j]);
                dfs(j, sum + candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ret;
    }
};

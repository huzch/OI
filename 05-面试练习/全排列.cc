// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path(n);
        vector<bool> vis(n);

        auto dfs = [&](this auto&& dfs, int i) ->void {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            for(int j = 0; j < n; ++j) {
                if(!vis[j]) {
                    vis[j] = true;
                    path[i] = nums[j];
                    dfs(i + 1);
                    vis[j] = false;
                }
            }
        };
        dfs(0);
        return ret;
    }
};

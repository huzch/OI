// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path(n);
        vector<bool> vis(n);
        ranges::sort(nums); //排序出现单调性，以实现剪枝

        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            for(int j = 0; j < n; ++j) {
                if(vis[j]) continue; // 每种排列中，一个位置只选一次
								// 当前元素与前一个元素相同时，任意选一种情况即可（前一个元素被选或者没被选）
                if(j > 0 && nums[j] == nums[j - 1] && !vis[j - 1]) continue; // !vis[j-1]效率更高
                vis[j] = true;
                path[i] = nums[j];
                dfs(i + 1);
                vis[j] = false;
            }
        };
        dfs(0);
        return ret;
    }
};

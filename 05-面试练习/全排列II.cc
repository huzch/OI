class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool st[15];
public:
    void dfs(vector<int>&nums) {
        if(path.size() == nums.size()) {
            ret.emplace_back(path);
            return;
        }

        for(int i=0; i<nums.size(); ++i) {
            if(st[i]) continue; //每种排列中，一个位置只选一次
            //当前元素与前一个元素相同时，任意选一种情况即可（前一个元素被选或者没被选）
            if(i > 0 && nums[i - 1] == nums[i] && !st[i - 1]) continue; //!st[i - 1]效率更高

            path.emplace_back(nums[i]);
            st[i] = true;
            dfs(nums);
            st[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //排序出现单调性，以实现剪枝
        path.reserve(nums.size());
        dfs(nums);
        return ret;
    }
};

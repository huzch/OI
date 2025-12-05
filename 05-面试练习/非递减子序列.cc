class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int n;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int pos) {
        if(path.size() > 1) ret.emplace_back(path);

        bool st[201] = {0}; //范围[-100,100],用数组代替哈希表
        for(int i=pos; i<n; ++i) {
            int x = nums[i];
            if(st[x + 100]) continue; //同一层不添加重复元素，防止子序列重复
            if(!path.empty() && path.back() > x) continue;
            st[x + 100] = true;
            path.emplace_back(x);
            dfs(nums, i + 1); //下一层从当前元素的下一个开始
            path.pop_back();
        }
    }
};

class Solution {
    static const int N = 10;
    vector<vector<int>> ret;
    vector<int> path;
    bool st[N];
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(nums);
        return ret;
    }

    void dfs(vector<int>& nums) {
        if(path.size() == n) {
            ret.emplace_back(path);
            return;
        }

        for(int i=0; i<n; ++i) {
            if(st[i]) continue;
            st[i] = true;
            path.emplace_back(nums[i]);
            dfs(nums);
            path.pop_back();
            st[i] = false;
        }
    }
};

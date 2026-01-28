// 方法一：dfs（回溯：选或不选）
// time: O(n2^n), space: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            dfs(i + 1); // 不选
            path.push_back(nums[i]);
            dfs(i + 1); // 选
            path.pop_back();
        };
        dfs(0);
        return ret;
    }
};

// 方法二：dfs（回溯：枚举选哪个）
// time: O(n2^n), space: O(n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int i) ->void {
            ret.push_back(path);
            for(int j = i; j < n; ++j) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ret;
    }
};

// 方法三：二进制枚举
// time: O(n2^n), space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        for(int i = 0; i < (1 << n); ++i) {
            vector<int> path;
            for(int j = 0; j < n; ++j) {
                if((i >> j) & 1) {
                    path.push_back(nums[j]);
                }
            }
            ret.push_back(path);
        }
        return ret;
    }
};

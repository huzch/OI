// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ret;
        vector<string> path;

        auto check = [&](int l, int r) {
            while(l < r) {
                if(s[l] != s[r]) return false;
                ++l, --r;
            }
            return true;
        };

        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            for(int j = i; j < n; ++j) {
                if(check(i, j)) {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1); // 考虑[j+1,n-1]如何分割
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ret;
    }
};

// 方法：dfs（回溯，选或不选）
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;

        auto dfs = [&](this auto&& dfs, int l, int r) {
            if(r == n) {
                ret.push_back(path);
                return;
            }

            if(l < n) {
                path += '(';
                dfs(l + 1, r);
                path.pop_back();
            }

            if(r < l) {
                path += ')';
                dfs(l, r + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ret;
    }
};

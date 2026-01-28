// 方法：dfs（回溯：枚举选哪个）
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> path(n, string(n, '.'));
        vector<bool> col(n), diag1(2 * n), diag2(2 * n);

        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) {
                ret.push_back(path);
                return;
            }

            for(int j = 0; j < n; ++j) {
                if(!col[j] && !diag1[i + j] && !diag2[i - j + n]) {
                    col[j] = diag1[i + j] = diag2[i - j + n] = true;
                    path[i][j] = 'Q';
                    dfs(i + 1);
                    path[i][j] = '.';
                    col[j] = diag1[i + j] = diag2[i - j + n] = false;
                }
            }
        };
        dfs(0);
        return ret;
    }
};
// 全排列的变形

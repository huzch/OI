// 方法：动态规划
// time: O(n^2), space: O(n^2)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));
        f[0][1] = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return f[m][n];
    }
};

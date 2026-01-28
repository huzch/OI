// 方法：动态规划（完全背包）
// time: O(n^2), space: O(n)
class Solution {
    const int INF = 0x3f3f3f3f;
public:
    int numSquares(int n) {
        int x = sqrt(n);
        // f[i][j]: 前i个完全平方数中，和为n的最小数量
        vector<int> f(n + 1);
        for(int j = 1; j <= n; ++j) f[j] = INF;
        for(int i = 1; i <= x; ++i) {
            for(int j = i * i; j <= n; ++j) {
                f[j] = min(f[j], f[j - i * i] + 1);
            }
        }
        return f[n];
    }
};

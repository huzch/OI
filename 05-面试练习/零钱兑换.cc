// 方法：动态规划（完全背包）
// time: O(n^2), space: O(n)
class Solution {
    static constexpr int INF = 0x3f3f3f3f;
public:
    int coinChange(vector<int>& coins, int amount) {
        // f[i][j]: 前i种硬币面额中，恰好为j的金额的最小个数
        int n = coins.size();
        vector<int> f(amount + 1);
        for(int j = 1; j <= amount; ++j) f[j] = INF;
        for(int i = 1; i <= n; ++i) {
            for(int j = coins[i - 1]; j <= amount; ++j) {
                f[j] = min(f[j], f[j - coins[i - 1]] + 1);
            }
        }
        return f[amount] == INF ? -1 : f[amount];
    }
};

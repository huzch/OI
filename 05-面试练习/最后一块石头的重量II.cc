// 方法：动态规划（01背包）
// time: O(n*sum), space: O(sum)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 建模转化：[a,b,c,d] -> b-c+d-a，最终结果为带正负号的表达式
        // 分为正号堆(和为x)与负号堆(和为y)，则最终结果为|x-y|的最小值
        // 要使得|x-y|最小，则要求其中一堆的和最接近sum/2(x+y=sum)
        // 转化为01背包，体积与价值均为数字本身
        // f[i][j]:前i个物品中，总体积不超过sum/2的价值最大和
        int sum = 0;
        for(int x: stones) sum += x;

        int n = stones.size(), t = sum / 2;
        vector<int> f(t + 1);
        for(int i = 1; i <= n; ++i) {
            for(int j = t; j >= stones[i - 1]; --j) {
                f[j] = max(f[j], f[j - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - f[t] * 2;
    }
};

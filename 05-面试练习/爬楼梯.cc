// 方法一：动态规划
// time: O(n), space: O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1);
        f[0] = f[1] = 1;
        for(int i=2; i<=n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};

// 方法二：动态规划(空间优化)
// time: O(n), space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c = 1;
        for(int i=2; i<=n; ++i) {
            c = a + b;
            a = b, b = c;
        }
        return c;
    }
};

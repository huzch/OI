// 方法一：动态规划
// time: O(n), space: O(n)
class Solution {
    int sum, maxsum, minsum;
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 寻找maxsum与minsum, ret = max(maxsum, sum - minsum)
        // f[i]:以i结尾的最大子段和
        // f[i] = max(f[i-1], 0) + nums[i]
        // g[i]:以i结尾的最小子段和
        // g[i] = min(g[i-1], 0) + nums[i]
        int n = nums.size();
        vector<int> f(n), g(n);
        f[0] = g[0] = sum = maxsum = minsum = nums[0];
        for(int i=1; i<n; ++i) {
            f[i] = max(f[i-1], 0) + nums[i];
            g[i] = min(g[i-1], 0) + nums[i];
            sum += nums[i];
            maxsum = max(maxsum, f[i]);
            minsum = min(minsum, g[i]);
        }

        if(sum == minsum) return maxsum;
        return max(maxsum, sum - minsum);
    }
};

// time: O(n), space: O(1)
class Solution {
    int f, g, sum, maxsum, minsum;
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        f = g = sum = maxsum = minsum = nums[0];
        for(int i=1; i<n; ++i) {
            f = max(f, 0) + nums[i];
            g = min(g, 0) + nums[i];
            sum += nums[i];
            maxsum = max(maxsum, f);
            minsum = min(minsum, g);
        }

        if(sum == minsum) return maxsum;
        return max(maxsum, sum - minsum);
    }
};

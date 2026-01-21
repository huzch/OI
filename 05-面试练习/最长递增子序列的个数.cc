// 方法一：动态规划
// time: O(n^2), space: O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1); // f[i]:以nums[i]为结尾的最长递增子序列的长度
        vector<int> g(n, 1); // g[i]:以nums[i]为结尾的最长递增子序列的个数

        int ret = 0, len = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    if(f[j] + 1 > f[i]) {
                        f[i] = f[j] + 1;
                        g[i] = g[j]; // 重置计数
                    } else if(f[j] + 1 == f[i]) {
                        g[i] += g[j]; // 累加计数
                    }
                }
            }

            if(f[i] > len) {
                len = f[i];
                ret = g[i];
            } else if(f[i] == len) {
                ret += g[i];
            }
        }
        return ret;
    }
};

// 方法二：贪心+二分+前缀和
// time: O(nlogn), space: O(n)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> d, cnt;
        for(int x: nums) {
            int i = find(d.size(), [&](int mid){return d[mid].back() >= x;}); // 二分定行
            int c = 1;
            if(i > 0) { // 查找上一行符合的方案数
                int k = find(d[i - 1].size(), [&](int mid){return d[i - 1][mid] < x;}); // 二分定列
                c = cnt[i - 1].back() - cnt[i - 1][k]; // 利用前缀和，计算<x的区间方案数和
            }
            if(i == d.size()) {
                d.push_back({x});
                cnt.push_back({0, c}); // 前缀和哨兵0
            } else {
                d[i].push_back(x);
                cnt[i].push_back(cnt[i].back() + c); // 累加前缀和
            }
        }
        return cnt.back().back();
    }

    int find(int n, auto&& f) {
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(f(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

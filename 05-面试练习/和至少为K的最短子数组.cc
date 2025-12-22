// 由于数组中有负数(没有单调性)，所以不能滑动窗口
// 方法：前缀和+单调队列
// time: O(n), space: O(n)
class Solution {
    deque<int> q; //单调递增队列，存储前缀和下标
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> f(n + 1); //前缀和,下标从1开始,方便处理边界
        for(int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + nums[i - 1];
        }

        int ret = n + 1;
        q.push_back(0); //处理边界，以包含从数组开头开始的子数组
        for(int i = 1; i <= n; ++i) {
            while(!q.empty() && f[q.back()] >= f[i]) q.pop_back();
            q.push_back(i);
            // 记录[q.front() + 1, i]的子数组
            while(!q.empty() && f[i] - f[q.front()] >= k) {
                ret = min(ret, i - q.front());
                q.pop_front();
            }
        }
        return ret == n + 1 ? -1 : ret;
    }
};

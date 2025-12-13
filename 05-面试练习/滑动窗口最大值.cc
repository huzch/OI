// 方法一：堆（优先队列）
// time: O(nlogn), space: O(n)
class Solution {
    priority_queue<pair<int, int>> hp; //<num, idx>
    vector<int> ret;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ret.reserve(n - k + 1);
        for(int i=0; i<n; ++i) {
            hp.emplace(nums[i], i);
            // 若当前最大值不在窗口内，则弹出，直到找到窗口内的最大值
            int l = i - k + 1; //窗口左边界
            while(hp.top().second < l) hp.pop();
            if(l >= 0) ret.emplace_back(hp.top().first);
        }
        return ret;
    }
};

// 方法二：单调队列
// time: O(n), space: O(n)
class Solution {
    deque<int> q; //单调递减队列，维护窗口最大值
    vector<int> ret;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ret.reserve(n - k + 1);
        for(int i=0; i<n; ++i) {
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            q.emplace_back(i);
            int l = i - k + 1; //窗口左边界
            if(!q.empty() && q.front() < l) q.pop_front();
            if(l >= 0) ret.emplace_back(nums[q.front()]);
        }
        return ret;
    }
};

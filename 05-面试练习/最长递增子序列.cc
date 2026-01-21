// 方法一：动态规划
// time: O(n^2), space: O(n);
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1); // f[i]: 以nums[i]为结尾的最长递增子序列的长度
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return ranges::max(f);
    }
};

// 方法二：贪心+二分
// time: O(nlogn), space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> g; // g[i]: 长度为i+1的递增子序列末尾元素的最小值
        for(int x: nums) {
            // 由定义得知：g必为单调递增（反证法），故可二分查找
            auto it = ranges::lower_bound(g, x);
            if(it == g.end()) g.push_back(x);
            else *it = x; // 若g存在>=x的元素，则进行替换（贪心，尽可能减小序列末尾，增加变长的可能）
        }
        return g.size();
    }
};

// time: O(nlogn), space: O(1)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int end = 0; // g数组的长度
        for(int x: nums) {
            int l = 0, r = end;
            while(l < r) { // [l, r)
                int mid = (l + r) >> 1;
                if(nums[mid] >= x) r = mid; // 左边界二分
                else l = mid + 1;
            }
            nums[l] = x;
            if(l == end) ++end;
        }
        return end;
    }
};

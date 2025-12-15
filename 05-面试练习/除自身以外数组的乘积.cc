// 方法一：前缀后缀积
// time: O(n), space: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n), ret(n);
        // 前缀积
        prev[0] = nums[0];
        for(int i=1; i<n; ++i) {
            prev[i] = prev[i - 1] * nums[i];
        }
        // 后缀积
        next[n - 1] = nums[n - 1];
        for(int i=n-2; i>=0; --i) {
            next[i] = next[i + 1] * nums[i];
        }

        ret[0] = next[1], ret[n - 1] = prev[n - 2];
        for(int i=1; i<n-1; ++i) {
            ret[i] = prev[i - 1] * next[i + 1];
        }
        return ret;
    }
};

// 空间优化
// time: O(n), space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        ret[n - 1] = nums[n - 1];
        for(int i=n-2; i>=0; --i) {
            ret[i] = ret[i + 1] * nums[i];
        }

        int prev = 1; //前缀积
        for(int i=0; i<n-1; ++i) {
            ret[i] = prev * ret[i + 1];
            prev *= nums[i];
        }
        ret[n - 1] = prev;
        return ret;
    }
};

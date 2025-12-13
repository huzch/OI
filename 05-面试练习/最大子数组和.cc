// 方法一：前缀和+set排序
// time: O(nlogn), space: O(n)
class Solution {
    set<int> s;
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN, sum = 0;
        for(int num: nums) {
            sum += num;
            ret = max(ret, sum - min(*s.begin(), 0));
            s.insert(sum);
        }
        return ret;
    }
};

// 方法二：前缀和+贪心
// time: O(n), space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = INT_MIN, sum = 0, minsum = 0;
        for(int num: nums) {
            sum += num;
            ret = max(ret, sum - minsum);
            minsum = min(minsum, sum);
        }
        return ret;
    }
};

// 方法三：动态规划
// time: O(n), space: O(1)
class Solution {
public:
    // f[i]: 以i结尾的最大子数组和
    // f[i] = max(f[i-1], 0) + nums[i]
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        for(int i=1; i<n; ++i) {
            f[i] = max(f[i - 1], 0) + nums[i];
        }
        return ranges::max(f);
    }
};

// 空间优化
class Solution {
public:
    // f[i]: 以i结尾的最大子数组和
    // f[i] = max(f[i-1], 0) + nums[i]
    int maxSubArray(vector<int>& nums) {
        int f = 0, ret = INT_MIN;
        for(int num: nums) {
            f = max(f, 0) + num;
            ret = max(ret, f);
        }
        return ret;
    }
};

// 方法四：分治（线段树简化，无实际建堆操作）
class Solution {
    struct node {
        // sum:区间和(线段树基础属性), max:最大子段和
        // lmax:左边界为l的最大子段和, rmax:右边界为r的最大子段和
        int sum, max, lmax, rmax;
    };
public:
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).max;
    }

    node get(vector<int>& a, int l, int r) {
        if(l == r) return {a[l], a[l], a[l], a[l]};
        int mid = (l + r) >> 1;
        node lt = get(a, l, mid);
        node rt = get(a, mid + 1, r);
        return pushup(lt, rt);
    }

    node pushup(node& l, node& r) {
        int sum = l.sum + r.sum;
        int max = ::max(::max(l.max, r.max), l.rmax + r.lmax);
        int lmax = ::max(l.lmax, l.sum + r.lmax);
        int rmax = ::max(r.rmax, r.sum + l.rmax);
        return {sum, max, lmax, rmax};
    }
};

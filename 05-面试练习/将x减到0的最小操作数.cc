// 方法一：递归解，超时
class Solution {
    int ret = INT_MAX;
public:
    void dfs(vector<int>& nums, int l, int r, int x, int cnt) {
        if(x == 0) {
            ret = min(ret, cnt);
            return;
        } else if(x < 0) return;
        if(l > r) return;

        dfs(nums, l + 1, r, x - nums[l], cnt + 1);
        dfs(nums, l, r - 1, x - nums[r], cnt + 1);
    }

    int minOperations(vector<int>& nums, int x) {
        dfs(nums, 0, nums.size() - 1, x, 0);
        return ret == INT_MAX ? -1 : ret;
    }
};

// 方法二：滑动窗口（需要转化思路，正难则反）
// 删除两边的操作数最少 <=> 中间保留的最长
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //目标：找到满足条件（数组之和等于sum-x）的最长子数组的长度
        int sum = 0;
        for(int num: nums) sum += num;

        int target = sum - x;
        if(target < 0) return -1; //target为负，而元素为正，故不存在目标子数组
        if(target == 0) return nums.size(); //target为0，只有空数组满足

        int cur = 0, len = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n) {
            cur += nums[right++];
            while(cur >= target) {
                if(cur == target) len = max(len, right - left);
                cur -= nums[left++];
            }
        }

        //len为0，表示虽然target为正，但是找不到数组之和恰好等于target的子数组
        return len == 0 ? -1 : n - len;
    }
};

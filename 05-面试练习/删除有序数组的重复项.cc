class Solution {
public:
    // 删除排序数组中的重复项，但允许最多保留 m 个重复元素
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int m = 1, j = m; //初始区间长度为m，就算都是重复元素也刚好满足要求
				if(m > n) return n; //边界情况
        for(int i=m; i<n; ++i) {
            // 维护有效区间[0,j-1],j为等待插入的位置
            // 每次比较当前元素与有效区间倒数第m个元素
            // nums[j-m] == nums[i] 说明区间已经有m个该元素，应该跳过第m+1个
            if(nums[j-m] != nums[i]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

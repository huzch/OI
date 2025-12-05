// 方法一：排序
// time: O(nlogn), space: O(n)
// 拷贝一份数组再排序，然后与原数组对比，相异的部分即为中段数组

// 方法二：数学
// time: O(n), space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // 假设中段数组边界为[L,R]
        // 中段数组的min不为nums[L],max不为nums[R](否则可并入左右数组)
        // nums[L-1] < min < nums[L] < ... < nums[R] < max < nums[R+1]
        // min为[L,n-1]最小值,max为[0,R]最大值
        int l = 0, r = 0;
        int min = INT_MAX, max = INT_MIN, n = nums.size();
        for(int i=0; i<n; ++i) {
            if(max > nums[i]) r = i; //最后比max小的就是右边界
            else max = nums[i];
            if(min < nums[n - i - 1]) l = n - i - 1; //最后比min大的就是左边界
            else min = nums[n - i - 1];
        }
        return l == r ? 0 : r - l + 1; //单个元素不算
    }
};

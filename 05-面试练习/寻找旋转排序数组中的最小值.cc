// 方法：二分
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), end = nums[n - 1];
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] <= end) r = mid; // mid位于右（最小值所在区间）
            else l = mid + 1;
        }
        return nums[l];
    }
};

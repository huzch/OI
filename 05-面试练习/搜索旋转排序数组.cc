// 方法：二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), end = nums[n - 1];
        int l = 0, r = n - 1; // 左闭右开写法，r看情况写n-1还是n
        while(l < r) {
            int mid = (l + r) >> 1;
            if(target > end && nums[mid] <= end) r = mid; // target在左，mid在右
            else if(nums[mid] > end && target <= end) l = mid + 1; // mid在左，target在右
            else { // target和mid在同一区间
                if(nums[mid] >= target) r = mid;
                else l = mid + 1;
            }
        }
        return nums[l] == target ? l : -1;
    }
};

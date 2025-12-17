class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // nums[i] < x < nums[i+1]时，x选择i+1作为插入位置，故为右边界
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l + r) >> 1; //左中点
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

// 方法：双指针
// time: O(n), space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1; // 维护非零区间
        for(int i = 0; i < n; ++i) {
            if(nums[i]) {
                swap(nums[i], nums[++j]);
            }
        }
    }
};

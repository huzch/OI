// 方法：双指针
// time: O(n), space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        // 维护[0,i-1]区间, i为待插入位置
        while(i < n) {
            // 找到下一个不为0的元素
            while(j < n && nums[j] == 0) ++j;
            nums[i++] = j == n ? 0 : nums[j++];
        }
    }
};

// 方法：原地哈希
// time: O(n), space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            // 只关注[1,n]的正整数x, 将其置换到下标为x-1的地方(原地哈希)
            while(1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i=0; i<n; ++i) {
            // 遇到首个不符合正整数哈希的，则为缺失的最小正整数
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1; //若[1,n]均存在，则缺失的为n+1
    }
};

// 方法：原地哈希
// time: O(n), space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int& x: nums) {
            // 只关注[1,n]的正整数x, 将其置换到下标为x-1的地方(原地哈希)
            while(1 <= x && x <= n && x != nums[x - 1]) {
                swap(x, nums[x - 1]);
            }
        }

        for(int i = 1; i <= n; ++i) {
            // 遇到首个不符合正整数哈希的，则为缺失的最小正整数
            if(i != nums[i - 1]) return i;
        }
        return n + 1; //若[1,n]均存在，则缺失的为n+1
    }
};

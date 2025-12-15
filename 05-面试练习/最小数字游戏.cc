// 方法一：堆（优先队列）
// time: O(nlogn), space: O(n)

// 方法二：排序
// time: O(nlogn), space: O(1)
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        ranges::sort(nums);
        for(int i=0; i<nums.size(); i+=2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};

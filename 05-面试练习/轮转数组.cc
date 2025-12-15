// 方法一：模拟
// time: O(n), space: O(n)

// 方法二：翻转
// time: O(n), space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        ranges::reverse(nums); // AB => B逆A逆
        reverse(nums.begin(), nums.begin() + k); // B逆A逆 => BA逆
        reverse(nums.begin() + k, nums.end()); // BA逆 => BA
    }
};

// 方法：贪心
// time: O(n), space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), ret = 0;
        int cur = 0; // 当前跳跃步数能到达的最远边界
        int next = 0; // 下一跳跃步数能到达的最远边界
        for(int i = 0; cur < n - 1; ++i) {
            next = max(next, i + nums[i]);
            if(i == cur) {
                cur = next;
                ++ret;
            }
        }
        return ret;
    }
};

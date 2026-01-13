// 方法: 贪心
// time: O(n), space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0; //维护可到达的最远下标
        // maxi >= n - 1时, 提前跳出
        for(int i = 0; maxi < nums.size() - 1; ++i) {
            if(i > maxi) return false;
            maxi = max(maxi, i + nums[i]);
        }
        return true;
    }
};

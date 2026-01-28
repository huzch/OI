// 方法：双指针
// time: O(n^3), space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> ret;
        for(int a = 0; a < n - 3; ++a) {
            int64_t x = nums[a];
            if(a > 0 && nums[a - 1] == x) continue;
            if(x + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break; // 优化一
            if(x + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
            for(int b = a + 1; b < n - 2; ++b) {
                int64_t y = nums[b];
                if(b > a + 1 && nums[b - 1] == y) continue;
                if(x + y + nums[b + 1] + nums[b + 2] > target) break; // 优化一
                if(x + y + nums[n - 2] + nums[n - 1] < target) continue; // 优化二
                int64_t t = target - x - y;
                int c = b + 1, d = n - 1;
                while(c < d) {
                    if(nums[c] + nums[d] < t) ++c;
                    else if(nums[c] + nums[d] > t) --d;
                    else {
                        int p = nums[c], q = nums[d];
                        ret.push_back({(int)x, (int)y, p, q});
                        while(c < d && nums[c] == p) ++c;
                        while(c < d && nums[d] == q) --d;
                    }
                }
            }
        }
        return ret;
    }
};

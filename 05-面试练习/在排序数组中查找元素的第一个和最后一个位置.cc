// 方法：二分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        auto lower_bound = [&](int t) {
            int l = 0, r = n;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(nums[mid] >= t) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        int begin = lower_bound(target);
        int end = lower_bound(target + 1) - 1;
        if(begin > end) return {-1, -1};
        return {begin, end};
    }
};

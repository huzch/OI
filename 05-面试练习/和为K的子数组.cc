// 方法：前缀和+哈希表
// time: O(n), space: O(n)
class Solution {
    unordered_map<int, int> hash; //<sum, cnt>
public:
    int subarraySum(vector<int>& nums, int k) {
        // 和为k=>前缀和为sum-k
        int ret = 0, sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            ++hash[sum]; //包含hash[0] = 1
            sum += nums[i];
            if(hash.count(sum - k)) ret += hash[sum - k];
        }
        return ret;
    }
};

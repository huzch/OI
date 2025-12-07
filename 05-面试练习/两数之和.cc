// 双变量化为单变量
// 以i结尾找前面，而不是以i开头找后面
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // nums[i] + nums[j] == target, 由于枚举左边i比较困难，所以枚举右边j
        // 访问nums[j]时，找已遍历的数中，是否存在target - nums[i]
        unordered_map<int, int> idx; //<nums[i], i>
        for(int j=0; j<nums.size(); ++j) {
            if(idx.count(target - nums[j])) {
                return {idx[target - nums[j]], j};
            } else idx[nums[j]] = j;
        }
        return {};
    }
};

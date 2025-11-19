// 1.将0转换为-1，题目就可以转换为求“和为0的最长子数组”
// 2.和为k的子数组，就可以用到前缀和
// 3.求以i结尾的和为k的子数组，就可以转换为求和为sum-k的前缀和
// 4.用哈希表优化，边遍历边统计
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash; //<前缀和,前缀和结尾下标>
        int sum = 0, len = 0;
        //由于未遍历数组前，前缀和为0，所以结尾下标为-1
        hash[0] = -1;
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i] ? 1 : -1;
            //哈希表中只记录第一次出现（即结尾下标最小）的前缀和，这样才能使得子数组长度最长
            if(!hash.count(sum)) hash[sum] = i;
            else len = max(len, i - hash[sum]);
        }
        return len;
    }
};

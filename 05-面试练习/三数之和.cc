class Solution {
    vector<vector<int>> ret;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums); //排序寻求优化
        int n = nums.size();
        for(int i=0; i<n-2; ++i) {
            int x = nums[i];
            if(i > 0 && x == nums[i - 1]) continue; //跳过重复
            if(x + nums[i + 1] + nums[i + 2] > 0) break; //最小都大于0，不可能找到
            if(x + nums[n - 2] + nums[n - 1] < 0) continue; //x增大还有可能找到
            
            //固定一个数后，有序数组寻找两数之和，双指针O(n)
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = x + nums[l] + nums[r];
                if(sum < 0) ++l;
                else if(sum > 0) --r;
                else {
                    ret.push_back({x, nums[l++], nums[r--]}); //找到一个三元组继续，后续可能还有
                    while(l < r && nums[l] == nums[l - 1]) ++l;
                    while(r > l && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        return ret;
    }
};

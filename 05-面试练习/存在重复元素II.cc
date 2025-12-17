// 方法一：哈希表（枚举右,维护左）
// time: O(n), space: O(n)
class Solution {
    unordered_map<int, int> ht;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); ++i) {
            int x = nums[i];
            if(ht.count(x) && i - ht[x] <= k) return true;
            else ht[x] = i;
        }
        return false;
    }
};

// 方法二：哈希表（滑动窗口）
// time: O(n), space: O(k)
class Solution {
    unordered_set<int> ht;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); ++i) {
            int x = nums[i];
            if(ht.count(x)) return true;
            else ht.insert(x);

            // 维护大小为k+1的窗口
            if(i >= k) ht.erase(nums[i - k]);
        }
        return false;
    }
};

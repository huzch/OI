// 方法一：排序
// time: O(nlogn), space: O(logn)

// 方法二：哈希表
// time: O(n), space: O(n)
class Solution {
    unordered_set<int> ht;
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int x: nums) {
            if(ht.count(x)) return true;
            else ht.insert(x);
        }
        return false;
    }
};

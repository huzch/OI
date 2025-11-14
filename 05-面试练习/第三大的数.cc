// 方法一：set 
// time: O(nlogn) space: O(n)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); //去除+排序
        auto it = s.rbegin();
        if(s.size() >= 3) ++it, ++it;
        return *it;
    }
};

// 方法二：大小为3的set
// time: O(n) space: O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num: nums) {
            s.insert(num);
            if(s.size() > 3) { //仅维护大小为3的set，保存前三大的数
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

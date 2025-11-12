// 方法一：list
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        list<int> ret;
        for(int num: nums) {
            if(num % 2 == 0) ret.emplace_front(num);
            else ret.emplace_back(num);
        }
        return vector<int>(ret.begin(), ret.end());
    }
};

// 方法二：双指针
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] % 2 == 0) ++left;
            else if(nums[right] % 2 != 0) --right;
            else swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

// 方法三：partition
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [](int x){return !(x & 1);});
        return nums;
    }
};

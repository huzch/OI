class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), len = 0;
        unordered_map<int, int> hash; //<水果种类,水果数量>

        int left = 0, right = 0; //滑动窗口左右边界
        while(right < n) {
            ++hash[fruits[right]];
            while(hash.size() > 2) {
                if(--hash[fruits[left]] == 0) {
                    hash.erase(fruits[left]);
                }
                ++left;
            }
            len = max(len, right - left + 1);
            ++right;
        }

        return len;
    }
};

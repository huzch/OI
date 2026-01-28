// 方法：贪心
// time: O(n), space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, minPrice = INT_MAX;
        for(int price: prices) {
            minPrice = min(minPrice, price);
            ret = max(ret, price - minPrice);
        }
        return ret;
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ret = 0, n = tickets.size();
        for(int i = 0; i < n; ++i) {
            if(i <= k) ret += min(tickets[i], tickets[k]);
            else ret += min(tickets[i], tickets[k] - 1);
        }
        return ret;
    }
};

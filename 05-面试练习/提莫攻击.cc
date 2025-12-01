class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        int begin = 0, n = timeSeries.size();
        timeSeries.emplace_back(INT_MAX); //处理边界
        for(int i=0; i<n; ++i) {
            if(timeSeries[i] + duration - 1 < timeSeries[i + 1]) {
                ret += timeSeries[i] + duration - timeSeries[begin];
                begin = i + 1;
            }
        }
        return ret;
    }
};

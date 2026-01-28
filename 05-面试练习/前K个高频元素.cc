// 方法：桶排序
// time: O(n), space: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxCnt = 0;
        unordered_map<int, int> cnt;
        for(int x: nums) {
            ++cnt[x];
            maxCnt = max(maxCnt, cnt[x]);
        }

        vector<vector<int>> buckets(maxCnt + 1);
        for(auto& [x, c]: cnt) {
            buckets[c].push_back(x);
        }

        vector<int> ret;
        for(int i = maxCnt; i >= 0; --i) {
            ret.insert(ret.end(), buckets[i].begin(), buckets[i].end());
            if(ret.size() == k) return ret;
        }
        return ret;
    }
};

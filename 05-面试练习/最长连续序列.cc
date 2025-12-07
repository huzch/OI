class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> hash(nums.begin(), nums.end());
        for(int x: hash) {
            // 若x-1存在，则x不为最长序列开头
            if(hash.count(x - 1)) continue;
            int y = x + 1;
            while(hash.count(y)) ++y;
            ret = max(ret, y - x); //[x, y-1]
            // 优化：若存在序列长度>=总长度一半，则为最长的
            if(ret * 2 >= hash.size()) break;
        }
        return ret;
    }
};

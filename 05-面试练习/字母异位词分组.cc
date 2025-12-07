class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto& str: strs) {
            auto s = str;
            ranges::sort(s); //字母异位词排序后相等，作为哈希键
            hash[s].emplace_back(str);
        }

        vector<vector<string>> ret; ret.reserve(hash.size());
        for(auto& [_, pack]: hash) ret.emplace_back(pack);
        return ret;
    }
};

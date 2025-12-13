class Solution {
    int hash[256];
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int l = 0, r = 0, n = s.size();
        while(r < n) {
            char in = s[r];
            ++hash[in];
            while(hash[in] > 1) {
                char out = s[l++];
                --hash[out];
            }
            ret = max(ret, r - l + 1);
            ++r;
        }
        return ret;
    }
};

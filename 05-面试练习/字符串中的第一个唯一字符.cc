// 方法一：哈希表
class Solution {
    int ht[256];
public:
    int firstUniqChar(string s) {
        for(char ch: s) ++ht[ch];
        for(int i = 0; i < s.size(); ++i) {
            if(ht[s[i]] == 1) return i;
        }
        return -1;
    }
};

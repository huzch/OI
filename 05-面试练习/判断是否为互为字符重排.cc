// 方法一：哈希表
// time: O(n), space: O(1)
class Solution {
    int ht1[26], ht2[26];
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        for(int i = 0; i < s1.size(); ++i) {
            ++ht1[s1[i] - 'a'], ++ht2[s2[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i) {
            if(ht1[i] != ht2[i]) return false;
        }
        return true;
    }
};

// 方法二：排序
// time: O(nlogn), space: O(1)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        ranges::sort(s1); ranges::sort(s2);
        return s1 == s2;
    }
};

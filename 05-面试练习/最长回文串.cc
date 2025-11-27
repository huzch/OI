class Solution {
    unordered_map<char, int> hash;
public:
    int longestPalindrome(string s) {
        for(char ch: s) ++hash[ch];

        bool flag = false; //标记是否有奇数个的字符
        int len = 0;
        for(auto& [ch, cnt]: hash) {
            if(cnt & 1) { //注意&优先级小于==，所以尽量不写等值判断
                len += cnt - 1;
                flag = true;
            } else len += cnt;
        }
        return flag ? len + 1 : len;
    }
};

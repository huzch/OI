class Solution {
public:
    string longestPalindrome(string s) {
        // 中心扩展
        int pos = 0, len = 0, n = s.size();
        for(int i=0; i<2*n-1; ++i) {
            // 同时枚举奇数和偶数的回文子串
            int l = i / 2, r = (i + 1) / 2;
            while(l >= 0 && r < n && s[l] == s[r]) {
                --l, ++r;
            }
            if(len < r - l - 1) {
                pos = l + 1, len = r - l - 1;
            }
        }
        return s.substr(pos, len);
    }
};

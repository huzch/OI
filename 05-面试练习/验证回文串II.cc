// 贪心
class Solution {
    int cnt = 1; //可以删除的字符数
public:
    bool dfs(const string& s, int l, int r) {
        if(l >= r) return true;

        if(s[l] == s[r]) return dfs(s, l + 1, r - 1);
				// 当s[l] != s[r]时，可以验证[l + 1, r]和[l, r - 1]两个区间子串
        if(cnt-- > 0) return dfs(s, l + 1, r) || dfs(s, l, r - 1);
        return false;
    }
    
    bool validPalindrome(string s) {
        return dfs(s, 0, s.size() - 1);
    }
};

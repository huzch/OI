// 方法一：unordered_map
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> base, cur; //<字符,字符个数>
        for(char ch: t) ++base[ch]; //记录目标字符串的字符个数

        int n = s.size(), m = base.size();
        int len = INT_MAX, begin = -1;
        int cnt = 0; //cnt记录满足要求的字符种类的个数
        int left = 0, right = 0; //窗口左右边界
        while(right < n) {
            char ch1 = s[right];
            if(base.count(ch1) && ++cur[ch1] == base[ch1]) ++cnt; //新增字符后，等于目标字符个数
            while(cnt == m) {
                int curLen = right - left + 1;
                if(len > curLen) len = curLen, begin = left;
                char ch2 = s[left];
                if(base.count(ch2) && cur[ch2]-- == base[ch2]) --cnt; //删除字符前，等于目标字符个数
                ++left;
            }
            ++right;
        }

        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};

// 方法二：手动实现（数组作为简单哈希表）
class Solution {
    int base[256], cur[256];
public:
    string minWindow(string s, string t) {
        //int base[256] = {0}, cur[256] = {0}; //<字符,字符个数>
        int m = 0;
        for(char ch: t) {
            if(++base[ch] == 1) ++m; //记录目标字符串的字符个数
        }

        int n = s.size();
        int len = INT_MAX, begin = -1;
        int cnt = 0; //cnt记录满足要求的字符种类的个数
        int left = 0, right = 0; //窗口左右边界
        while(right < n) {
            char ch1 = s[right];
            if(base[ch1] && ++cur[ch1] == base[ch1]) ++cnt; //新增字符后，等于目标字符个数
            while(cnt == m) {
                int curLen = right - left + 1;
                if(len > curLen) len = curLen, begin = left;
                char ch2 = s[left];
                if(base[ch2] && cur[ch2]-- == base[ch2]) --cnt; //删除字符前，等于目标字符个数
                ++left;
            }
            ++right;
        }

        return len == INT_MAX ? "" : s.substr(begin, len);
    }
};

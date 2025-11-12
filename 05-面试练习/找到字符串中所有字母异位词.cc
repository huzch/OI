// 方法一：容器整体比较
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> sCnt, pCnt;
        for(char ch: p) ++pCnt[ch];

        int n = s.size(), m = p.size();
        for(int i=0; i<m; ++i) ++sCnt[s[i]];

        vector<int> ret;
        for(int i=m; i<n; ++i) {
            if(sCnt == pCnt) ret.emplace_back(i - m); //利用容器==比较
            char out = s[i - m], in = s[i];
            if(--sCnt[out] == 0) sCnt.erase(out);
            ++sCnt[in];
        }

        if(sCnt == pCnt) ret.emplace_back(n - m); //最后一次边界情况
        return ret;
    }
};

// 方法二：kinds记录
class Solution {
    int sCnt[256], pCnt[256];
public:
    vector<int> findAnagrams(string s, string p) {
        int skinds = 0, pkinds = 0;
        for(char ch: p) {
            if(++pCnt[ch] == 1) ++pkinds;
        }

        vector<int> ret;
        int n = s.size(), m = p.size();
        int left = 0, right = 0, len = 0;
        while(right < n) {
            char in = s[right++];
            if(pCnt[in] && ++sCnt[in] == pCnt[in]) ++skinds;
            ++len;
            while(len == m) {
                if(skinds == pkinds) ret.emplace_back(left);
                char out = s[left++];
                if(pCnt[out] && sCnt[out]-- == pCnt[out]) --skinds;
                --len;
            }
        }
        return ret;
    }
};

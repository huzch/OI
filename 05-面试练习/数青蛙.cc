class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string sound = "kcroak";
        char pre[256]{}; //<curCh, preCh>
        for(int i=1; i<sound.size(); ++i) {
            pre[sound[i]] = sound[i - 1];
        }

        int cnt[256]{}; //<ch, cnt>
        for(char ch: croakOfFrogs) {
            char preCh = pre[ch];
            // 消耗前一个字母，获得当前字母
            // 若前面没有字母，则新开一个蛙鸣序列，必须由c开启
            if(cnt[preCh]) --cnt[preCh];
            else if(ch != 'c') return -1;
            ++cnt[ch];
        }

        // 最后若有除k外的其他字母存在，则非法
        if(cnt['c'] || cnt['r'] || cnt['o'] || cnt['a']) return -1;
        return cnt['k'];
    }
};

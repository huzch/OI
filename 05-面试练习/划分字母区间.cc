// 方法：贪心
// time: O(n), space: O(1)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int lastPos[26] = {0};
        for(int i = 0; i < n; ++i) {
            lastPos[s[i] - 'a'] = i;
        }

        vector<int> ret;
        int begin = 0, end = 0;
        for(int i = 0; i < n; ++i) {
            end = max(end, lastPos[s[i] - 'a']);
            if(i == end) {
                ret.push_back(end - begin + 1);
                begin = i + 1;
            }
        }
        return ret;
    }
};

// 方法：栈
// time: O(n), space: O(1)
class Solution {
    string ret;
public:
    string removeDuplicates(string s) {
        for(char ch: s) {
            if(!ret.empty() && ch == ret.back()) {
                ret.pop_back();
            } else ret += ch;
        }
        return ret;
    }
};

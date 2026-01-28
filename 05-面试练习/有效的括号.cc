// 方法：栈
// time: O(n), space: O(n)
class Solution {
public:
    bool isValid(string s) {
        if(s.size() & 1) return false;
        
        stack<char> st;
        unordered_map<char, char> ht = {{')','('},{'}','{'},{']','['}};
        for(char ch: s) {
            if(!ht.count(ch)) st.push(ch);
            else {
                if(st.empty()) return false;
                if(ht[ch] != st.top()) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};

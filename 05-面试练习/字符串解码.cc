// 方法：栈
// time: O(n), space: O(n)
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<int> nums;
        string t;

        for(int i = 0; i < n; ++i) {
            char ch = s[i];
            if(isdigit(ch)) {
                int x = 0;
                while(isdigit(s[i])) {
                    x = x * 10 + (s[i++] - '0');
                }
                --i;
                nums.push(x);
            } else if(ch == '[') t += ch;
            else if(isalpha(ch)) t += ch;
            else {
                string tmp;
                while(t.back() != '[') {
                    tmp += t.back(); t.pop_back();
                }
                t.pop_back(); // 弹出'['
                ranges::reverse(tmp);

                int k = nums.top(); nums.pop();
                while(k--) t += tmp;
            }
        }
        return t;
    }
};

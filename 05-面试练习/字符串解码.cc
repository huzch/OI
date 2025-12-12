class Solution {
    stack<int> nums;
    string str;
public:
    string decodeString(string s) {
        for(int i=0; i<s.size(); ++i) {
            char ch = s[i];
            if(isdigit(ch)) {
                int x = 0;
                while(isdigit(s[i])) {
                    x = x * 10 + (s[i++] - '0');
                }
                --i; //补偿++i
                nums.push(x);
            }
            else if(ch == '[') str += ch;
            else if(isalpha(ch)) str += ch;
            else if(ch == ']') {
                string tmp;
                while(str.back() != '[') {
                    tmp += str.back(); str.pop_back();
                }
                str.pop_back(); //弹出'['
                reverse(tmp.begin(), tmp.end());

                int k = nums.top(); nums.pop();
                while(k--) str += tmp;
            }
        }
        return str;
    }
};

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;

        stack<char> st; //存储左括号
        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else { //右括号匹配，成功则弹出栈顶并继续，失败返回
                if(st.empty()) return false; //栈为空，无匹配括号
                if((ch == ')' && st.top() == '(') 
                || (ch == '}' && st.top() == '{') 
                || (ch == ']' && st.top() == '[')) {
                    st.pop();
                    continue;
                }
                return false; //栈不为空，无匹配括号
            }
        }

        return st.empty(); //检查是否有多余左括号
    }
};

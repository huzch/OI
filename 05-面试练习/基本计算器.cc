// 有一元运算符、有括号
class Solution {
    unordered_map<char, int> pri = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
public:
    int calculate(string s) {
        // 比基本计算器II更难，有括号，有一元运算符
        int n = s.size();
        // nums类型为long，防止整数溢出
        stack<long> nums; stack<char> ops;
        nums.push(0); //处理首个数为负
        for(int i=0; i<n; ++i) {
            char ch = s[i];
            if(ch == ' ') continue;
            if(ch == '(') {
                ops.push(ch);
                //处理括号内首个数为负
                while(s[i + 1] == ' ') ++i;
                if(s[i + 1] == '-') nums.push(0);
            } else if(isdigit(ch)) {
                long x = 0;
                while(isdigit(s[i])) {
                    x = x * 10 + (s[i++] - '0');
                }
                --i; //补偿++i
                nums.push(x);
            } else if(ch == ')') {
                while(ops.top() != '(') calc(nums, ops);
                ops.pop(); //弹出'('
            } else {
                // op优先级高的，先计算
                while(!ops.empty() && ops.top() != '(') {
                    if(pri[ops.top()] >= pri[ch]) {
                        calc(nums, ops);
                    }
                }
                ops.push(ch);
            }
        }

        // 此时op栈优先级非递减，可顺序计算
        while(!ops.empty()) calc(nums, ops);
        cout << nums.size() << endl;
        return nums.top();
    }

    void calc(stack<long>& nums, stack<char>& ops) {
        if(nums.size() < 2 || ops.empty()) return;
        long x = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if(op == '+') nums.top() += x;
        else if(op == '-') nums.top() -= x;
        else if(op == '*') nums.top() *= x;
        else if(op == '/') nums.top() /= x;
    }
};

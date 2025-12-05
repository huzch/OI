// 无一元运算符、无括号
class Solution {
    unordered_map<char, int> pri = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> nums; stack<char> ops;
        for(int i=0; i<n; ++i) {
            char ch = s[i];
            if(ch == ' ') continue;
            if(isdigit(ch)) {
                int x = 0;
                while(isdigit(s[i])) {
                    x = x * 10 + (s[i++] - '0');
                }
                --i; //补偿++i
                nums.push(x);
            } else {
                // 优先级高的先计算
                while(!ops.empty()) {
                    if(pri[ops.top()] >= pri[ch]) {
                        calc(nums, ops);
                    } else break;
                }
                ops.push(ch);
            }
        }

        // 最后剩下的op，从栈顶往下优先级非递增，所以可以顺序计算
        while(!ops.empty()) calc(nums, ops);
        return nums.top();
    }

    void calc(stack<int>& nums, stack<char>& ops) {
        if(nums.size() < 2 || ops.empty()) return;
        int x = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if(op == '+') nums.top() += x;
        else if(op == '-') nums.top() -= x;
        else if(op == '*') nums.top() *= x;
        else if(op == '/') nums.top() /= x;
    }
};

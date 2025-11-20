class MyQueue {
public:
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        int front = out.top();
        out.pop();
        return front;
    }
    
    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    stack<int> in;
    stack<int> out;
};

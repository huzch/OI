class MyStack {
public:
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        while(in.size() > 1) {
            tmp.push(in.front());
            in.pop();
        }

        int top = in.front();
        in.pop();
        in.swap(tmp);
        return top;
    }
    
    int top() {
        return in.back();
    }
    
    bool empty() {
        return in.empty() && tmp.empty();
    }
private:
    queue<int> in;
    queue<int> tmp;
};

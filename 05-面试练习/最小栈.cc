class MinStack {
public:
    void push(int val) {
        if(st.empty()) st.emplace(val, val);
        else st.emplace(val, min(val, st.top().second));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st; //<插入值,插入后当前栈中最小值>
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

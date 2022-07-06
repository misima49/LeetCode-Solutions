class MinStack {
    stack<long> st;
    long minElement;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        minElement = 1e9;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minElement = val;
        } else if(val < minElement) {
            st.push((2L)*val - minElement);
            minElement = val;
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < minElement) {
            minElement = 2L*minElement - st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1e8;
        if(st.top() < minElement) {
            return minElement;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
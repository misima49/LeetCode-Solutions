class MyStack {
    queue<int> q;
public:
    void push(int x) {
        int curSz = q.size();
        q.push(x);
        while(curSz--) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        int tp = q.front();
        q.pop();
        return tp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
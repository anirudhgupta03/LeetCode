class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    
    MinStack() {
        while(s1.size()){
            s1.pop();
        }
        while(s2.size()){
            s2.pop();
        }
    }
    
    void push(int val) {
        s1.push(val);
        
        if(s2.empty()){
            s2.push(val);
        }
        else if(val <= s2.top()){
            s2.push(val);
        }
    }
    
    void pop() {
        if(!s2.empty() && s1.top() == s2.top()){
            s2.pop();
        }
        if(!s1.empty()){
            s1.pop();
        }
    }
    
    int top() {
        if(!s1.empty()){
            return s1.top();
        }
        return 0;
    }
    
    int getMin() {
        if(!s2.empty()){
            return s2.top();
        }
        return 0;
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

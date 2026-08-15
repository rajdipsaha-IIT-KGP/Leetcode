class MinStack {
public:
   stack<pair<int,int>>st;
   int mn;
    MinStack() {
         mn = INT_MAX;
    }
    
    void push(int value) {
        mn = min(mn,value);
        st.push({value,mn});
    }
    
    void pop() {
         st.pop();

    if (st.empty())
        mn = INT_MAX;
    else
        mn = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
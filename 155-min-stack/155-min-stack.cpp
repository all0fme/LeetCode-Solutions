class MinStack {
public:
    
   priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int,int> mp;
    stack<int> st;
    MinStack() {
       
    }
    
    void push(int val) {
        st.push(val);
       pq.push(val);
        mp[val]++;
        
    }
    
    void pop() {
       int x = st.top();
        
        st.pop();
        mp[x]--;
       
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        while(mp[pq.top()]==0)
            pq.pop();
        return pq.top();
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
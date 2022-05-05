class MyStack { 
public:
    MyStack() {
        // default constructor
    }
    
    queue<int>q;
    
    void push(int x) {  // TC:O(1)
        q.push(x);
    }
    
    int pop() {  // TC:O(N)
        
        int n = q.size();
        while( n-- > 1){
            q.push(q.front());
            q.pop();
        }
        
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        int n = q.size();
        while( n-- > 1){
            q.push(q.front());
            q.pop();
        }
        
        int top = q.front();
        q.pop();
        q.push(top);
        return top;
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
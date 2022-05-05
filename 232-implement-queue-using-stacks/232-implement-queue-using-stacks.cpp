class MyQueue {  // push - O(1) peek = pop = O(amortized)
public:
    MyQueue() {
        // default constructor
    }
    
    stack<int>s1,s2; // we take two stacks
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop()
   {
        // checking if S2 is empty or not. if YES we will push all elements from S1 to S2. if NOT we will pop its top element
        
        if(s2.empty()== true){
            
            while(s1.empty()== false){
            s2.push(s1.top());
            s1.pop();
        }
            
            int x = s2.top();
            s2.pop();
            return x;
            
        }
        
        else { // S2 is not empty
        int x = s2.top();
        s2.pop();
        return x;
            
        }
        
    }
    
    int peek() {
         // checking if S2 is empty or not. if YES we will push all elements from S1 to S2. if NOT we will pop its top element
        
        if(s2.empty()== true){
            
            while(s1.empty()== false){
            s2.push(s1.top());
            s1.pop();
        }
            
            int x = s2.top();
            return x;
            
        }
        
        else { // S2 is not empty
        int x = s2.top();
        return x;
            
        }
    }
    
    bool empty() {
        return (s1.empty() and s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
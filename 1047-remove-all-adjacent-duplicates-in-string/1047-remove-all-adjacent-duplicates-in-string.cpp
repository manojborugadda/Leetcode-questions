class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans; // storing the answer
        
        for(auto x:s){
            if(st.empty() == true){ // if the stack is empty PUSH the elements
                st.push(x);
            }else if(st.top() == x){ // if the top element of stack is equal to element,POP the top element of the stack
                st.pop();
            }else{ //if the top element of stack is NOT Equal to element,PUSH to the stack
                st.push(x);
            }
        }
        
        while(st.empty() == false){ // pushing all the elements to the answer String
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
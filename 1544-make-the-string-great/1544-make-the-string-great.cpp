class Solution { //TC:O(N)  SC:O(N)
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.length();
        for(int i = 0;i<n;i++) {
            if(st.empty() == true) {//if initially the stack is empty we push the character
                st.push(s[i]);
                continue;
            }
            if(abs(st.top() - s[i]) == 32) { //checking the condition for ---> s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
                st.pop();
            }else{
                st.push(s[i]);//if all the above cases are failed we push into the stack
            }
        }
        
    //*******************////////inserting elements from the stack to the string
        string str;//answer string
        while(st.empty() == false) {
            str += st.top();
            st.pop();
        }
        reverse(begin(str),end(str));
        return str;
    }
};
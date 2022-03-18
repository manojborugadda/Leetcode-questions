class Solution { 
                //Time Complexity :- BigO(N)

                //Space Complexity :- BigO(N)
public:
    string removeDuplicateLetters(string s) {
        vector<int>LastIndex(26,0);
        for(int i = 0;i<s.length();i++){
            LastIndex[ s[i] - 'a' ] = i; // track the lastIndex of character presence
        }
        
        vector<bool>seen(26,false);  // this keeps tracking the "seen" or not
        stack<char>st;
        for(int i = 0;i<s.size();i++){
           int curr = s[i]-'a';
            if(seen[curr]) continue;
            while(st.empty()==false and st.top()>s[i] and LastIndex[st.top()-'a'] > i){
                seen[ st.top()- 'a' ] = false;   // pop out and mark unseen
                st.pop();
            }
            
            st.push(s[i]); // add into stack
            seen[curr] = true; // we should mark as "seen" of that
        }
        
        string ans;
        while(st.empty()==false){
            ans = ans+st.top();
            st.pop();
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {  // Time Complexity = Space Complexity = O(N)
public:
    string decodeString(string s) {
        
        string ans = ""; // answer 
        stack<pair<string,int>>st;//Stack to store the string between [] and the number of times it needs to be generated
        int num = 0;
        for(int i = 0;i<s.length();i++)
        {
            // condition 1 --------------------------------------------------
            if(isdigit(s[i])){
                num = num*10 + (s[i]-48); //ASCII value of 0 is 48. we want the actual number in INTEGER
            }
            // condition 2--------------------------------------------------
// if we got "[" we make the substring variable blank and number zero to prepare it for the next iteration
            else if(s[i]=='['){
                st.push({ans,num});
                ans = "";
                num = 0;
            }
            // condition 3 ---------------------------------------------------
//As a "]" is encountered we generate the given substring according to 'num' times given on stack top.We add the string at stack top and generated string so that it may be processed again if required
            else if(s[i]==']'){
                
                string temp = ans;
               for(int i = 1;i<st.top().second;i++){
                    temp = temp+ans;
                }
                ans = st.top().first+temp;
                st.pop();
            }
            
            // condition 4 ---------------------------------------------------------
            else{ // s[i] is character 
                ans = ans+s[i];
            }
        }
        
        return ans;
    }
};
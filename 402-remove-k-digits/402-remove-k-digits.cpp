class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        
        // let the number is 1423
        // smallest number is 123 if any number has a small number infront of             // it than we can remove that previous number
        
        stack<char>s;
        for(int i=0;i<num.size();i++)
        {
            while(k>0 and s.size()>0 and s.top()>num[i])
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        
        // to handle case like "1234567"   just remove from back
        
        while(k>0)
        {
            s.pop();
            k--;
        }
        // reverse a string
        string ans=""; 
        while(!s.empty()){
            ans += s.top(); 
            s.pop();
        }
        reverse(ans.begin(),ans.end());
         int i=0;
		/* corner case : count the leading number of zeros*/
        while(ans[i] == '0'){
            i++;
        }
		
        return (ans.substr(i) == "")? "0": ans.substr(i);
    }
};
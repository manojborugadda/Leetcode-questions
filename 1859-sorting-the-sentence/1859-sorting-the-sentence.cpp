class Solution {
public:
    string sortSentence(string s) {
        string res;
        int start = 0;
        map<int,string>mp;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i])) //keep loop running till we find a number
            {
                
                //add substring from s[start] to s[i-1] index in map with key s[i]
                mp[s[i]] = s.substr(start,i-start);
                
                i++; //skip next char as it will be a space
                start = i+1;
            }
        }
        
         //since map is sorted, we will concat the values for keys 1,2,3,....,n
        for(auto x:mp){
            res  = res+x.second+" ";
        }
        
          //ignore the space after last word and return
        return res.substr(0, res.size() - 1);
    }
};
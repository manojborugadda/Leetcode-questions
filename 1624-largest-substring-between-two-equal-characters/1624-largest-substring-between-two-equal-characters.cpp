class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {   
        unordered_map<char,int>mp;
        int maxlen = -1;
        int n = s.length();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(mp.find(c)!=mp.end()){
                maxlen = max(maxlen,i-mp[c]-1);
            }
            else
                mp[c] = i;
        }
        return maxlen;
    }
};
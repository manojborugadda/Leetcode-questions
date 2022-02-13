class Solution {
public:
    int balancedStringSplit(string s){
    int cnt_l=0,cnt_r=0,ans=0;
    for(int i=0;i<s.size();i++)   
    {
        if(s[i]=='R')
            cnt_r++;
        else
            cnt_l++;
        if(cnt_l==cnt_r)   
        {
            ans++;
            cnt_l=0;
            cnt_r=0;
        }
        
    }
    return ans;
    }
};
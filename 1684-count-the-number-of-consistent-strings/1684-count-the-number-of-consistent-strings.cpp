class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
     unordered_map<char,int>mp;
        for(auto i:allowed){
           mp[i] ++;
        }
        int ans=0;
        for(auto x:words){
            bool isconsistent = true;
            for(auto y:x){
                if(mp[y]==0){
                    isconsistent = false;
                    break;
                }
            }
            
            if(isconsistent==true)
                ans++;
        }
        
        return ans;
    }
};
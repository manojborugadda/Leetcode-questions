class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
         vector<string> ans;
        
        map<char,int> mp;
        
       for(int i=0;i<words[0].size();i++){
           mp[words[0][i]]++;
       }

        
        for(int i=1;i<words.size();i++)
        {
            map<char,int>  mp1;
            
            for(int j=0;j<words[i].size();j++){
                mp1[words[i][j]]++;
               }
            
            for(auto x: mp){
                if(mp1.find(x.first)!=mp.end()){
                    
                    if(mp1[x.first]!=x.second){
                     
                        mp[x.first]=min(x.second, mp1[x.first]);
                       }
                }
                else{
                     mp.erase(mp.find(x.first));
                    }
                }
          }

            for(auto x: mp){
                while(x.second--){
                    string s(1, x.first);
                    ans.push_back(s);
                }
                
            }
            
           return ans;
    }
        
};

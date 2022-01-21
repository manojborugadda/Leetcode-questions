class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
          unordered_map<int,int>mp1,mp2;
        for(auto x:arr){
            mp1[x]++;
        }
        for(auto k : mp1){
            mp2[k.second]++;
        }
        
        for(auto y:mp2){
            if(y.second > 1){
                return false;
            }
        }
        
        return true;
    }
};
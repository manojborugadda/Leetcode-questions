class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {   if(k<0) return 0; // absolute difference cannot be ZERO so we return 0;
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        
        int count=0;
          for(auto x:mp){
            if(k==0){    // absolute difference is ZERO means we should find the duplicate elements and increase the count
                if(x.second>1) count++;    // [3,1,4,1,5]   frequency of 1 is morethan ONE    
            }
              //k > 0
            else if(mp.find(x.first-k)!=mp.end()){
                    count++;
                }
            }
        return count;
    }
};
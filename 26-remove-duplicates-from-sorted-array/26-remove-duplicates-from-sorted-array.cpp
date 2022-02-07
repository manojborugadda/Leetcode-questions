class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int>ans;
        for(auto x:mp){
            
            while(x.second > 1){
                x.second--;
            }
            
            if(x.second==1) ans.push_back(x.first);
        }
        
            nums.clear()  ;    // clear() function is used to remove all the elements of the vector container, thus                                     making it size 0. 
            sort(ans.begin(),ans.end());
            nums = ans;
        
          return nums.size();
    }
    
};
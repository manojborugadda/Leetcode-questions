class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int>ans;
        
       for(auto x:mp){
           
           while(x.second > 2){
               x.second--;
           }
           
           if(x.second==1) ans.push_back(x.first);
           else if(x.second ==2){
               ans.push_back(x.first);
               ans.push_back(x.first); 
           }
           nums.clear()  ;    // clear() function is used to remove all the elements of the vector container, thus making it size 0. 
            sort(ans.begin(),ans.end());
            nums = ans;
       }
        return nums.size();

    }
};
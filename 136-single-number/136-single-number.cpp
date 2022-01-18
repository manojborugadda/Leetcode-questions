class Solution {
public:
    int singleNumber(vector<int>& nums)
    {   int ans;
           unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto it:mp){
            if(it.second == 1){
                ans =  it.first;
            }
        }
        return ans;
    }
};
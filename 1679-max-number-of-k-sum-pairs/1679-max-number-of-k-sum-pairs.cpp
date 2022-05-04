class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
    for(auto x:nums)
    {
        if(mp[k-x]) // if it is present in the MAP
        {
            //// removing the pairs from the MAP
            mp[(k-x)]--; 
            mp[x]--;
            
            count++;
        }
        mp[x]++;
    }
        return count;
    }
};
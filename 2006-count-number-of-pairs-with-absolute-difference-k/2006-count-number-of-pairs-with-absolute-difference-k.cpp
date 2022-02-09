class Solution {
public:
    int countKDifference(vector<int>& nums, int k)
    {
         unordered_map<int, int>mp;
        int ans = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i]+k)!=mp.end() or mp.find(nums[i]-k)!=mp.end()){
                ans+=(mp[nums[i]+k]+mp[nums[i]-k]);
            }
            mp[nums[i]]++;
        }
        
        return ans;
        
    }
};
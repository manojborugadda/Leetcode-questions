class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
         int n = nums.size();
        if(n <= 1)
            return false;
        unordered_map<int, int> mod;
        mod[0] = -1; 
        
        int curr_sum = 0;
        for(int i = 0; i < n; i++)
        {
            curr_sum += nums[i];
            curr_sum %= k;
            if(mod.find(curr_sum) != mod.end())
            {
                if(i - mod[curr_sum] >= 2) //size should be atleast 2
                    return true;
            }
             
            else   
              mod[curr_sum] = i;
        }
    
        return false;
        
    }
};
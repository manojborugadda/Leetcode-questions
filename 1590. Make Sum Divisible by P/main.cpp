class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        long totalSum = 0;
        for(auto &e : nums){
            totalSum += e;
        }

        int target = totalSum % p;
        //if target is zero then no need to remove any subarray
        if(target == 0)return 0;

        unordered_map<int,int>mp;
        mp[0] = -1;

        long curr = 0;
        int result = INT_MAX;

        for(int j = 0; j < n; j++){
            curr += nums[j];

            int prev = (curr - target + p) % p;
            if(mp.find(prev) != mp.end()){
                result = min(result, (j - mp[prev]));
            }
            mp[curr % p] = j;
        }
        return result == n ? -1 : result;
    }
};

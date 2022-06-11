class Solution {  //TC:O(N)   SC:O(1)
                                            ///SLIDING WINDOW problem  
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = -x;
        int res = -1 , left = 0 , right = 0 , sum = 0;
        
        for(auto x: nums) target  = target+x;
        
        if(target==0) return n;
        
        if(target < 0) return -1;
        
        for(right = 0 ; right < n ; right++) {
            sum = sum+nums[right];
            while(sum>target){
                sum = sum-nums[left++];
            }
            if(sum == target){
                res = max(res,right-left+1);
            }
        }
        return res == -1 ? -1 : nums.size()-res;
        
    }
};
class Solution {  //TC:O(N)  SC:O(1)
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 , right = 0 , n = nums.size(), sum = 0 , ans = INT_MAX;
        for(right = 0;right<n;right++){
            sum = sum+nums[right];
            while(sum >= target){
                ans = min(ans,right-left);
                sum = sum-nums[left++];
            }
            
        }
        return ans == INT_MAX ? 0 : ans+1;
    }
};
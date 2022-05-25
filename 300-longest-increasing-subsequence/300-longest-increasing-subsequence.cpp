class Solution {  // TC:O(N*2)  SC:O(N)--- as we are using extra space for DP
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1; // length of the "longest strictly increasing subsequence."( "LIS")
        vector<int>dp(n,1);  // DP of size "nums"
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){ //if the present value is greater than the previous value
                    dp[i] = max( dp[i] , dp[j]+1 );
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
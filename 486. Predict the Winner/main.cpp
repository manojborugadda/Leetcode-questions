class Solution {
public:
    int helper(int start , int end , vector<int>&nums,vector<vector<int>>&dp ) {
        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        if(start == end) {
            return nums[start];
        }

        int left = nums[start] - helper(start+1,end,nums,dp);
        int right = nums[end] - helper(start,end-1,nums,dp);
        return dp[start][end] = max(left,right);

        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return helper(0,n-1,nums,dp) >= 0 ;
    }
};

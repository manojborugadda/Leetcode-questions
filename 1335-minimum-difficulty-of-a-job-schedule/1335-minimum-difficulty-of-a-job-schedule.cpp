class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1; //base condition
        vector<vector<int>>dp(301,vector<int>(11,-1));
        return helper(dp,jobDifficulty,0,d,n);
    }
    
private:
    int helper(vector<vector<int>>&dp,vector<int>& nums,int i,int d,int n) {
        if(d == 1) return *max_element(begin(nums)+i,end(nums) );
        if(dp[i][d] != -1) return dp[i][d];
        int result = INT_MAX, curr = INT_MIN;
        for(int j = i;j <= n - d;j++) {
            curr = max(curr,nums[j]);
            result = min(result,curr+helper(dp,nums,j+1,d-1,n));
        }
        return dp[i][d] = result;
    }
};
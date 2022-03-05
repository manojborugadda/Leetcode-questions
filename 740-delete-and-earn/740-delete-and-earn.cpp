class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int maxelement= *max_element(nums.begin(),nums.end()); // Finding the maximum value present in the given vector
        
        vector<int>dp(maxelement+1,0); // dp[i] will store the maximum earning at the index i
    
        for(int n:nums) dp[n]++; // for any index i, the initial earning is equal to its frequency
        
        for(int i=2;i<=maxelement;++i){
            dp[i]=max(dp[i]*i+dp[i-2],dp[i-1]); // calculating the max earning for i
        }
        return dp[maxelement];
    }
};
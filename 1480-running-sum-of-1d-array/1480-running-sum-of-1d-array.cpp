class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
          vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1;i<n;i++){
            dp[i] = nums[i]+dp[i-1];
        }
        return dp;
    }
};
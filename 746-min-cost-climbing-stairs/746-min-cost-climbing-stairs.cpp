class Solution {  //TC:O(N)    SC:O(N)
public: 
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       vector<int>dp(n+1,0);
        dp[0] = cost[0];// minimum cost to reach the step 0 is cost[0] only
        dp[1] = cost[1];//minimum cost to reach the step 1 is taken as cost[1] as we can start from 0 index or 1 index as per the problem
        for(int i = 2;i<=n;i++){
            if(i==n){
                return dp[i] = min(dp[i-1],dp[i-2]);
            }
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return dp[n];
        
    }
};

//first of all we have to find the Minimum cost to pay to reach the ith Step. for that we take the DP array
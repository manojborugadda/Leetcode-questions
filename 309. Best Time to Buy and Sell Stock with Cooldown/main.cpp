class Solution { //TC:O(N) SC:O(N)
public:
    int solve(int i,int buy,vector<int>price,vector<vector<int>>&dp){
        int n=price.size();
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];

        if(buy){
            return dp[i][buy]=max(-price[i]+solve(i+1,0,price,dp),solve(i+1,1,price,dp));
        }
        else{
            return dp[i][buy]=max(price[i]+solve(i+2,1,price,dp),0+solve(i+1,0,price,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};

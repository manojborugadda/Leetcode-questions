class Solution {//TC:O(N^2) SC:O(N^2)
public:
    int recur(int i ,vector<int>& prices,int fee,int buyOrSell ,  vector<vector<int>>&dp ) {
        if( i >= prices.size()) return 0;
        if(dp[i][buyOrSell] != -1) return dp[i][buyOrSell];
        if(buyOrSell == 0) { // if we did buy the stock
            int sum1 = -prices[i] + recur(i+1 , prices,fee,1,dp);
            int sum2 =  recur(i+1,prices,fee,0,dp);
            return dp[i][buyOrSell] = max(sum1,sum2);
        }else { // if we did buy the stock
            int sum3 = prices[i]-fee + recur(i+1,prices,fee,0,dp);
            int sum4 = recur(i+1,prices,fee,1,dp);
            return dp[i][buyOrSell] = max(sum3,sum4);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return recur(0, prices, fee, 0 ,dp);
    }
};

/*
For i index:

If we already have a stock :
1.Hold it and move to next day.
2.Sell it, pay fee and move to next day.

If we don't have any stock:
1.Just go to next day.
2.Buy it and move to next day.

*/

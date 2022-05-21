class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int d7 = i , d30 = i;
            while(d7 < n and days[d7] < days[i]+7){
                ++d7;
            }
            while(d30 < n and days[d30] < days[i]+30){
                ++d30;
            }
            
            dp[i] = min({costs[0]+dp[i+1] , costs[1]+dp[d7]  , costs[2]+dp[d30]});
        }
        
        return dp[0];
    }
};
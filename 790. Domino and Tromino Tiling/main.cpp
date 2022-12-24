class Solution { //TC:O(N) SC:O(N)
public:
    int numTilings(int n) {
        long long  dp[1001];
        memset(dp,0,sizeof(dp));
        int MOD = 1e9+7;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4;i<=n;i++) {
            dp[i] = (2 * dp[i-1] + dp[i-3]);
            dp[i] %= MOD;
        }

         return dp[n];
    }
};

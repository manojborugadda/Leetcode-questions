class Solution {
public:
    int countOrders(int n) {
        long long dp[501];
        int mod = pow(10,9)+7;
         dp[1]=1L;
        dp[2]=6L;
        for(int i = 3;i<=n;i++){
            int oddno = 2*i - 1;
            int permutation = oddno*(oddno+1)/2;
             dp[i] = (permutation*dp[i-1])%mod;
        }
        return dp[n];
    }
};
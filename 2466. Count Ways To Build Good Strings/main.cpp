class Solution {//TC:O(N)  SC:O(N)
#define ll long long 
public:
    ll mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll>dp(high+1,-1);
        return recur(0,low,high,dp,zero,one);
    }

    int recur(ll len,int low, int high, vector<ll>&dp, int zero, int one) {
        ll ans = 0;
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];
        if(len>=low and len<=high)ans=1;
        ans = (ans%mod + recur(len+zero,low,high,dp,zero,one)%mod)%mod;
        ans = (ans%mod + recur(len+one,low,high,dp,zero,one)%mod)%mod;
        return dp[len] = ans;
        return ans;
    }
};

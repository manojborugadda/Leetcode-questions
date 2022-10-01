class Solution { ///BOTTOM UP APPROACH
public:                         //TC:O(N) SC:O(N)
    int numDecodings(string s) {
        int n = s.length();
         if(s[0] == '0' or n == 0) return 0; //1.base case
        vector<int>dp(n+1,0);
        if(n == 1) return 1;
        dp[0] = 1 , dp[1] = 1;  ///initialising the dp[0] and dp[1]
        for(int i = 2;i<n+1;i++) {
            int oneDigit = s[i-1] - '0';
            int secondDigit =  (s[i-2]-'0')*10 + oneDigit;
            
            if(oneDigit >= 1) {
                dp[i] += dp[i-1];
            }
            
            if(secondDigit >= 10 and secondDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
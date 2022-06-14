class Solution { //Dynamic Programming - Tabulation
public:
    // TC:O(M*N) SC:O(M*N)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length() , n = text2.length();
      vector<vector<int>> dp(m+1, vector<int> (n+1, 0));// DP declaring
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                //// comparing last elements of both strings
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n]; // return the right bottom corner cell which is dp[]m[n]
    }
};
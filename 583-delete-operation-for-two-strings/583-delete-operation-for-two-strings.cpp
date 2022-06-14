class Solution {
public:
    /*
    To find the the minimum number of steps required to make word1 and word2 the same.
Theminimumnumber ofsteps= length of  " s1 + length of s2 - 2 *length of LCS"

formula: M+N - 2*LCS

where- M-length of s1, N-length of s2

TC: O(MxN), SC: O(MxN)

*/
    int minDistance(string s1, string s2) {
         int m = s1.length() , n = s2.length();
      vector<vector<int>> dp(m+1, vector<int> (n+1, 0));//initialising DP
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n-2*dp[m][n];
    }
};
class Solution { // TC:O(M*N) SC:O(M*N)
public:
    // It is same as Longest common Subsequence but we have to pass the reverse of given string 
    int longestPalindromeSubseq(string text1) {
        string text2 = text1; // copying text1 to text2
        reverse(text2.begin(),text2.end()); // reversing the text2
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));//declaring the DP matrix of M*N
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                //// comparing last elements of both strings
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n]; // return the right bottom corner cell which is dp[]m[n]
    }
};
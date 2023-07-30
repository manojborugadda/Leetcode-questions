class Solution { //TC:O(N^3) SC:O(N^2)
public:// In time complexity = O(n^2) comes from DP and o(n) from internal recursion
    int recur(vector<vector<int>>&dp,int i , int j , string &s) {
        if(i == j) return 1;
        int minTurns = INT_MAX;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        for(int k = i;k<j;k++) {
            minTurns = min(minTurns , recur(dp,i,k,s) +  recur(dp,k+1,j,s));
        }

        return dp[i][j] = (s[i] == s[j]) ? minTurns - 1 : minTurns;

    }
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return recur(dp,0,n-1,s);
    }
};

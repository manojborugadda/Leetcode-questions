class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));  // filling the dp with 0's
        int count = 0; // number of palindromic substrings
        
        // we are filling in the DP for substring of length 1 
        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
            count++;
        }
        
        // for substring of length 2 
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;  // if the two contiguos sequence of characters are same or NOT
                count++;
            }
        }
        
        // we are filling DP for substring of length morethan or Equal to 3 
        for(int k = 3; k <= n ; k++){
            for(int i = 0 ; i < n-k+1 ; i++){
                int j = i+k-1;
// here we are checking the characters between i and j are PALINDROME are not along with the END and BEGIN characters
                if(s[i]==s[j] and dp[i+1][j-1]==1){ 
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
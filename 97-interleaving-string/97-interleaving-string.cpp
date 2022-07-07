class Solution { //dp Memoization
public:
    bool helper(string s1, string s2, string s3,int i, int j, int k, vector<vector<int>>&dp){
        //base condition
        if(i == s1.size() and j == s2.size() and k == s3.size()){
            return true;
        }
        //base condition
        if(i > s1.size() or  j > s2.size()){
            return false;
        }
        
        if(dp[i][j] != -1){ //if every cell is fixed we return the cell as answer
            return dp[i][j];
        }
        
        if(s3[k]==s1[i] and s3[k]==s2[j]){
            return dp[i][j] = helper(s1,s2,s3,i+1,j,k+1,dp) or helper(s1,s2,s3,i,j+1,k+1,dp);
        }else if(s3[k]==s1[i]){
            return dp[i][j] = helper(s1,s2,s3,i+1,j,k+1,dp);
        }else if(s3[k]==s2[j]){
             return dp[i][j] = helper(s1,s2,s3,i,j+1,k+1,dp);
        }else{
             return dp[i][j] = false;
        }
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length() , n = s2.length() , k = s3.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)); // dp array
        return helper(s1,s2,s3,0,0,0,dp);
    }
};
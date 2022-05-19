class Solution {
public:
    vector<vector<int>>directions={{-1,0},{0,-1},{1,0},{0,1}};// four directions: left, right, up, or down.
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n));// we are taking the DP same size of givenMatrix
    int longestPath = 0;
        for(int i = 0;i<m;i++){  // traversing through the matrix
            for(int j = 0;j<n;j++){
                longestPath = max(longestPath,dfs(m,n,i,j,matrix,dp));
            }
        }
        return longestPath; 
    }
    
    int dfs(int m,int n,int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int maxpath = 0; /// maximum path
        
         //if we have already the path length of the cell, we return it (dp concept)
        if(dp[i][j] > 0){  
            return dp[i][j] ;
        }
        ///else 
        for(auto x : directions){  // checking the UP,DOWN,RIGHT,LEFT cells 
            int a = i+x[0]; 
            int b = j+x[1];
            
            // boundary conditions 
            if(a >= 0 and b >=0 and a < m and b < n and matrix[i][j] < matrix[a][b]){
                maxpath = max(maxpath,dfs(m,n,a,b,matrix,dp));
            }
        }
        
        dp[i][j]  = maxpath+1;
        return maxpath+1;
        
    }
};
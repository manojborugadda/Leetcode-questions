class Solution {   //TC:O(M*N)  SC:O(M*N)
public:// DP problem ------------------>BOTTOM - UP approach 
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();///rows
        int n = grid[0].size();//columns
        vector<vector<int>>dp(m,vector<int>(n));//initialising the DP array of length M*N
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(i == m-1 and j != n-1){//if the cell's row is the LAST row
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }else if(i != m-1 and j == n-1){//if cell's column is the LAST column
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }else if(i != m-1 and j != n-1){ // if the cell is middle of the grid
                    dp[i][j] = grid[i][j] + min(dp[i][j+1] , dp[i+1][j]);
                }else{// if cell is grid[m][n] which is BOTTOM RIGHT CORNER
                    dp[i][j] = grid[i][j];
                }
            }
        }
        return dp[0][0];//returning the TOP LEFT CORNER cell which actually has the minimum path sum
    }
};
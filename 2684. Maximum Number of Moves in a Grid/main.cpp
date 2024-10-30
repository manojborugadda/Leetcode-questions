class Solution {
public:
    int dp[1001][1001];
    int m, n;
    int DFS(vector<vector<int>>& grid,int row,int col,int prev) {
        //if the current element in the cell is less than the previous element , we return -1
        if(row < 0 or row >= m or col < 0 or col >= n or grid[row][col] <= prev) {
            return -1;
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        return dp[row][col] = max({ 1 + DFS(grid,row - 1, col + 1 , grid[row][col]) , 1 + DFS(grid,row , col + 1 , grid[row][col]) , 1 + DFS(grid,row + 1, col + 1 , grid[row][col]) });
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<grid.size();i++) {
            ans = max(ans,DFS(grid,i,0,-1));
        }
        return ans;
    }
};

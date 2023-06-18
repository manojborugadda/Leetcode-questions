class Solution {//TC:O(N^2) + STACK SPACE
public:         //SC:O(1001*1001)
    int dp[1001][1001];
    int MOD  = 1e9+7;
    //DFS
    int recur(int i,int j,int prev,vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        if(i < 0 or j < 0 or i>= m or j >= n or grid[i][j] <= prev) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = recur(i,j-1,grid[i][j],grid);
        int right = recur(i,j+1,grid[i][j],grid);
        int up = recur(i+1,j,grid[i][j],grid);
        int down = recur(i-1,j,grid[i][j],grid);
        return dp[i][j] = (1+left+right+up+down)%MOD;

    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int ans =  0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<m;i++) {
            for(int j =0;j<n;j++) {
                ans = (ans + recur(i,j,-1,grid) )%MOD;
            }
        }
        return ans;
    }
};

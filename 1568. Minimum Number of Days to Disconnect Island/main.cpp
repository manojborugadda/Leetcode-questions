class Solution {//TC:O(M*N)^2  SC:O(M*N)
public:
    void DFS(int i , int j , vector<vector<bool>>&vis , int m  , int n , vector<vector<int>>& grid) {
        if(i >= m or j >= n or i < 0 or j < 0 or vis[i][j] == true or grid[i][j] == 0) {
            return;
        }
        vis[i][j] = true;
        DFS(i+1,j,vis,m,n,grid);
        DFS(i-1,j,vis,m,n,grid);
        DFS(i,j+1,vis,m,n,grid);
        DFS(i,j-1,vis,m,n,grid);
    }
    int isLandCount(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int islands = 0;
         for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1 and vis[i][j] == false) {
                    DFS(i,j,vis,m,n,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = isLandCount(grid);
        if(islands > 1 or islands == 0) {
            return 0;//we dont need to flip the 1 to 0 i.e land to water. already is satisfying the problem condition
        }

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    islands = isLandCount(grid);
                    if(islands > 1 or islands == 0)  {
                        return 1; // as we flipped one time we need to 1day
                    }
                    grid[i][j] = 1; //backtracking
                }
            }
        }
        return 2;
    }
};
//atmost 2 days is enough to make this graph to disconnected graph

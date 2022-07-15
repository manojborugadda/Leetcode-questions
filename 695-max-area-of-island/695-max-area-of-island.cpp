class Solution {
public:
    void dfs(vector<vector<int>>& grid,int&area,int i,int j, int r,int c)
    {
        //checking if the current cell is obeying the below conditions are Not i.e valid or NOT
        if(i<0 or j<0 or i>=r or j>=c or grid[i][j]==0){
            return;
        }
        //if valid increment area
        area++;
        //after incrementing the current area we have to make the cell 0 because we have SEEN or USED
        grid[i][j]=0;
        dfs(grid,area,i,j+1,r,c);
        dfs(grid,area,i,j-1,r,c);
        dfs(grid,area,i+1,j,r,c);
        dfs(grid,area,i-1,j,r,c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     int maxi=0;
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(grid[i][j]==1)
             {
                 int area=0;
                 dfs(grid,area,i,j,m,n);
                 maxi=max(maxi,area);
             }
             
         }
     }
        return maxi; ///maximum area of an island in grid
    }
};
class Solution {  //TC:O(M*N)   SC:O(N)
public:
    
    //helper function for DFS for calculating the no.of islands
    int dfs(vector<vector<char>>& grid,int i,int j,int R,int C){
        
        if(i< 0 or i>= R or j<0 or j>=C or grid[i][j]== '0'){
            return 0;
        }
        //else
        grid[i][j] = '0';
        dfs(grid,i+1,j,R,C);
        dfs(grid,i-1,j,R,C);
        dfs(grid,i,j+1,R,C);
        dfs(grid,i,j-1,R,C);
        return 1;
     }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int no_of_islands = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]== '1'){
                    no_of_islands += dfs(grid,i,j,m,n);
                }
            }
        }
        return no_of_islands;        
    }
};
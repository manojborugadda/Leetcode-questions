class Solution { //TC:O(M*N) SC:O(1)
public:
    void DFS(vector<vector<int>>& grid,int i,int j,int &count) {
        //check row wise
        for(int row = 0;row < grid.size();row++) {
            if(grid[row][j]) {
                grid[row][j] = 0; // after reaching the cell make it 0 so that we dont count that again
                count++;
                DFS(grid,row,j,count);
            }
        }

        //checking COLUMN wise now
        for(int col = 0;col<grid[i].size();col++) {
            if(grid[i][col]) {
                grid[i][col] = 0; // after reaching the cell make it 0 so that we dont count that again
                count++;
                DFS(grid,i,col,count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size() ;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<grid[i].size();j++) {
                if(grid[i][j]) {
                    int count = 0;
                    DFS(grid,i,j,count);
                    if(count > 1) {
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};

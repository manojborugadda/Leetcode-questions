class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
         queue<pair<pair<int,int>,int>>q;
         q.push({ {0,0} , 1});
        
        // base condition---------------
        // if there is only one  element  in the top-left Corner cell like [[0]] we return 1
        if(grid[0][0] == 0 and grid.size() == 1 and grid[0].size() == 1){
            return 1;
        }
// if the bottom-right corner cell OR top-left cell is 1 we return -1 as it says no clear path
        if(grid[n-1][n-1] == 1 or grid[0][0] == 1){
            return -1;
        } //---------------------------
        
        // for knowing of which cell we have visited previously we created a VISITED vector
        vector<vector<bool>>visited(n,vector<bool>(grid.size(),false));
        visited[0][0] = true;
        
        while(q.empty()==false){
            
            pair<int,int>p = q.front().first;
            int x = p.first;
            int y = p.second;
            int lengthOfPath = q.front().second;
            q.pop();
            // For the 8 directions of any cell in the 
            vector<pair<int,int>>neighbours = {
                                                {0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}
                                            };  
            
            for(pair<int,int>neighbour : neighbours )
            {
                int new_x = neighbour.first+x;
                int new_y = neighbour.second+y;
                
        if(new_x >= 0 and new_y >=0 and new_x < grid.size() and new_y < grid[0].size() and grid[new_x][new_y] ==0 and visited[new_x][new_y]==false){
                    
                    q.push({{new_x,new_y},lengthOfPath+1});
                    visited[new_x][new_y] = true;
                    
            // if we reach the" Right bottom cell "it means we have reached the last point in the clear path and we have to terminate the process by returning the LengthOfPath
                    if(new_x==grid.size()-1 && new_y==grid[0].size()-1) 
                    {
                        return lengthOfPath+1;
                    }
                }
            }
        }  
        return -1;  
    }
};
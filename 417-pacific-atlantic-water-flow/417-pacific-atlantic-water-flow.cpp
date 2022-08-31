class Solution { //TC:O(N^2) SC:O(N^2)
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int m = heights.size();
        int n  = heights[0].size();
        //Null exception condition
        if(heights.size() == 0 or m == 0 or n == 0){
            return ans;
        }
         vector<vector<bool>>pacific(m,vector<bool>(n,false));
         vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        for(int j = 0;j<n;j++){
            //for the top most EDGES as Pacific Ocean touches
            dfs(0,j,pacific,heights,INT_MIN); ///initially we keep the prevHeight as INT_MIN
            //for the bottom  EDGES as Atlantic Ocean touches
            dfs(m-1,j,atlantic,heights,INT_MIN);
        }
        
        for(int i = 0;i<m;i++) {
            //for the left most EDGES as Pacific Ocean touches
            dfs(i,0,pacific,heights,INT_MIN);
            //for the right most EDGES as Atlantic Ocean touches
            dfs(i,n-1,atlantic,heights,INT_MIN);
        }
        
        //building the answer
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(pacific[i][j] and atlantic[i][j]){
                    //if the cells are TRUE in both the Boolean Matrices we take those Indices
                    vector<int>indices;//temporary vector for storing INDICES
                    indices.push_back(i);
                    indices.push_back(j);
                    ans.push_back(indices);//pushing into the answer Vector
                }
            }
        }
        return ans;
    }
    
    void dfs(int i,int j,vector<vector<bool>>&canReach,vector<vector<int>>&matrix,int prevHeight) {
        //if we are already VISITED or the current height is less than Neighbour Height or for Negative conditions we RETURN
            if(i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or matrix[i][j] < prevHeight or canReach[i][j]) {
                return;
            }
        canReach[i][j] = true;  //marking the Cell as VISITED
        dfs(i+1,j,canReach,matrix,matrix[i][j]);
        dfs(i-1,j,canReach,matrix,matrix[i][j]);
        dfs(i,j+1,canReach,matrix,matrix[i][j]);
        dfs(i,j-1,canReach,matrix,matrix[i][j]);
        
    }
    
};
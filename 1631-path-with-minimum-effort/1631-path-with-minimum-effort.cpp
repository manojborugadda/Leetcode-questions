class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // for having the minimum value using MIN HEAP
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        // for direction in all 4 sides
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        
        int ans = 0;
        int n = heights.size();  // no of rows
        int m = heights[0].size();   // no:of columns
        
        // initially we push the {0,0,0} into the queue
        pq.push({0,0,0});
        
        while(pq.size()){
            auto result = pq.top();
            pq.pop();
            ans = max(ans,result[0]);
            
            int i = result[1];
            int j = result[2];
            
            if(heights[i][j]== -1){//if the block or cell is already VISITED we continue
                continue;
            }
            ///base condition
            if(i == n-1 and j == m-1){
                break;
            }
            
            // we are checking for particular cell Neighbours
            for(int d = 0;d<4;d++){
                int new_i = i + dir[d][0];
                int new_j = j + dir[d][1];
            if(new_i < 0 or new_j< 0 or new_i == n or new_j == m or heights[new_i][new_j]== -1)
                {
                    continue;
                }
                pq.push({abs(heights[i][j] - heights[new_i][new_j]) , new_i , new_j});
            }
              heights[i][j] = -1; // we have to mark VISITED after checking 
        }
        return ans;
    }
};
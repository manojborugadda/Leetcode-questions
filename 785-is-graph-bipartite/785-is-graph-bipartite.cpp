class Solution {  // TC : O(N) SC : O(N)
public:
    
    
    bool dfs(int node , vector<vector<int>>& graph , vector<int> &colour){
            for(auto x : graph[node]){
                
                if(colour[x] == -1){ // not coloured yet 
                    colour[x] = 1 - colour[node];  //reverse the color
                    
                if(dfs(x,graph,colour) == false)
                {
                    return false;   
                 }   
            }
            else if(colour[x]== colour[node]){ // already coloured and same colour
                    return false;
             }
                
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n,-1);  // initially keeping -1 in all cells
        for(int i = 0;i<n;i++){
            if(colour[i] == -1 ){
                colour[i] = 1;
                if(dfs(i,graph,colour) == false){
                    return false;
                }
            }
        }
            return true;
    }
};
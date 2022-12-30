class Solution {
public:
    void backtrack(vector<int>&path , vector<vector<int>>&result , int v ,vector<vector<int>>& graph) {
        if(v==graph.size()-1) //we have reached the last node(n-1)th node
        {
            result.push_back(path);
            return;
        }
        if(graph[v].empty()) return; //if there are no out going vertices
        
        for(int i=0;i<graph[v].size();i++) {
            path.push_back(graph[v][i]);
            backtrack(path,result,graph[v][i],graph);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        backtrack(path,result,0,graph);
        return result;
    }
};

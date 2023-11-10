class Solution {
public:
    void dfs(int node, map<int, vector<int>> &adj, map<int, int> &vis, vector<int> &ans)
    {
        vis[node] = 1;
        ans.push_back(node);

        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it, adj, vis, ans);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        vector<int> ans;
        map<int, vector<int>> adj; 
        map<int, int> vis; 

        for(auto it : adjacentPairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }   
        int start;
        for(auto it : adj)
        {
            if(it.second.size() == 1)
            {
                start = it.first;
                break;
            }
        }
        dfs(start, adj, vis, ans);
        return ans;
    }
};

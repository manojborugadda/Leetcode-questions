class Solution { //TC:O(N) SC:O(N)
public:
    
    vector<int> res;
    
    vector<int> count_node;
    
    void dfs_count(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
                continue;
            
            dfs_count(adj, v, u);
            
            count_node[u] += count_node[v];
            
            res[u] += res[v] + count_node[v];
        }
        
        count_node[u]++;
    }
    
    void dfs_final(vector<vector<int>>& adj, int u, int parent)
    {
        for(auto v : adj[u])
        {
            if(v == parent)
            {
                continue;
            }
            
            res[v] = res[u] - count_node[v] + (adj.size() - count_node[v]);
            
            dfs_final(adj, v, u);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        res.resize(n, 0);
        
        count_node.resize(n, 0);
        
        // create adjacency list
        
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        // calculate all the nodes in a subtree
        
        dfs_count(adj, 0, -1);
        
        // calculate the distances for every node to the other nodes 
        
        dfs_final(adj, 0, -1);
        
        return res;
    }
};

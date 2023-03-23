class Solution {//TC:O(connections)  SC:O(n) , n is the no.of nodes
public: 

    void bfs(int node,vector<int>adj[],vector<bool>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int cur_node=q.front();
            q.pop();

            for(auto it: adj[cur_node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
         if(connections.size()<n-1) return -1;
        vector<bool>vis(n,false);
        vector<int>adj[n];

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt-1;
    }
};

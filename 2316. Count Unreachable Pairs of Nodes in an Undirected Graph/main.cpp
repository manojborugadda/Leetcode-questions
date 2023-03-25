class Solution {  //TC:O(V+E)  SC:O(V+E)
public://we solved this problem using BFS
    void bfs(int i,vector<vector<int>>&adj, vector<bool>&visited,long long &size) {
        queue<int>q;
        q.push(i);
        visited[i] = true;
        size++; //gives the size of particular component
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto &node : adj[x]) {
                if(!visited[node]) {
                    visited[node] = true;
                    size++;
                    q.push(node);
                }
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        ///building the adjacency matrix
        for(auto &node:edges) {
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }

        long long remainingNodes = n , result = 0;

        for(int i = 0;i<n;i++) {
            if(!visited[i]) {
                long long size = 0;
                bfs(i,adj,visited,size);
                result += (size)*(remainingNodes - size);
                remainingNodes -= size; //after finding and calculating every component and its size we have to update the total no of nodes remaining
            }
        }

        return result;
    }
};

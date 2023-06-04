class Solution {//this question is good example for DFS 
public://TC:O(V+E)  SC:O(V+E)
    void dfs(int idx,vector<bool>&visited,vector<int>adj[]) {
        visited[idx] = true;
        for(auto x : adj[idx]) {
            if(!visited[x]) {
                dfs(x,visited,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        //creating the adjacency list
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i!=j and isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int provinceCount = 0;
        vector<bool>visited(n,false);
        for(int i =0;i<n;i++) {
            if(!visited[i]) {
                provinceCount += 1;
                dfs(i,visited,adj);
            }
        }
        return provinceCount;
    }
};

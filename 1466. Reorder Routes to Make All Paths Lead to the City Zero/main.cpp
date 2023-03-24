#define OUTGOING 1
#define INCOMING 0
#define NOT_VISITED 0
#define VISITED 1

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(make_pair(it[1],OUTGOING));
            adj[it[1]].push_back(make_pair(it[0],INCOMING));
        }

        vector<bool>visited(n,NOT_VISITED);
        int count =0;
        queue<int>q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto it:adj[u]){
                if(visited[it.first]==NOT_VISITED){
                    if(it.second==OUTGOING)count++;
                    q.push(it.first);
                    visited[it.first] = VISITED;
                }
            }
        }
        return count;
    }
};

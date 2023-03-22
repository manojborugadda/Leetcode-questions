
class Solution {//TC:O(E+V)  SC:O(E+V)
public:///solving using BFS here and we can do by DFS
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> gr(n+1);//we have taken PAIR because we want to keep track of DISTANCE aswell
        for(auto edge : roads){ //standard way of making Adjacency MATRIX
            gr[edge[0]].push_back({edge[1], edge[2]}); // u-> {v, dis}
            gr[edge[1]].push_back({edge[0], edge[2]}); // v-> {u, dis}
        }

        vector<bool> vis(n+1, false);
        queue<int> q;
        q.push(1); vis[1] = true;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            for(auto& [v, dis] : gr[node]){
                ans = min(ans, dis);
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

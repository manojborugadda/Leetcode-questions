class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {//TC:O(N)
        vector<set<int>>adj(n);
        for(auto &v : roads) {//creating the adjacency list
            adj[v[0]].insert(v[1]);
            adj[v[1]].insert(v[0]);
        }
        //traversing the adjacency list for calculating the maximumNetworkRank

        int maxRank = 0;
        for(int i= 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {///TC:O(N^2)
                int ans = 0;
                //checking the duplicate condition and decreasing by 1
                //If a road is directly connected to both cities, it is only counted once.
                if(find(adj[i].begin() , adj[i].end() , j) != adj[i].end()) {
                    ans = adj[i].size() + adj[j].size() - 1;
                }else {
                    ans = adj[i].size() + adj[j].size();
                }
                maxRank = max(maxRank ,ans);
            }
        }
            return maxRank;
    }
};

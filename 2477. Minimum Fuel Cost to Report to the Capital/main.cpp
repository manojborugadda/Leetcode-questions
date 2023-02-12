class Solution { //TC:O(N)  SC:O(N)
public:
    long long fuel;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<int>adj[n];
        for(auto &road : roads) {
            const int a = road[0];
            const int b = road[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0,-1,adj,seats);
        return fuel;
    }

    long long dfs(int currCity ,int prevCity,vector<int>adj[],int seats ) {
        int people = 1; //every city has one people
        for(auto &nextCity : adj[currCity]) {
            if(nextCity != prevCity) {
                people += dfs(nextCity,currCity,adj,seats);
            }
        }
        
        if(currCity != 0) {//// final destination 
                fuel += ceil(double(people)/seats);
        }
        return people;
    }
};

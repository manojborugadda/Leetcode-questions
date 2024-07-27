class Solution {
private:
    void solve(vector<vector<pair<int,int>>> &adjList,vector<vector<int>> &dis){
        int n=adjList.size();
        for(int src=0;src<n;src++){
            dis[src][src]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            while(!pq.empty()){
                int currNode_dis=pq.top().first;
                int currNode=pq.top().second;
                pq.pop();
                if(currNode_dis>dis[src][currNode]) continue;
                for(auto it:adjList[currNode]){
                    int neighbour=it.first;
                    int wt=it.second;
                    if(dis[src][neighbour]>currNode_dis+wt){
                        dis[src][neighbour]=currNode_dis+wt;
                        pq.push({dis[src][neighbour],neighbour});
                    }
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int m=source.size();
        int n=original.size();
        vector<vector<pair<int,int>>> adjList(26);
        vector<vector<int>> dis(26,vector<int>(26,1e9));
        for(int i=0;i<n;i++){
            int u,v,w;
            u=original[i]-'a';
            v=changed[i]-'a';
            w=cost[i];
            adjList[u].push_back({v,w});
            // adjList[v].push_back({u,w});
        }
        long long ans=0;
        solve(adjList,dis);
        for(int i=0;i<m;i++){
            if(source[i]==target[i]) continue;
            if(dis[source[i]-'a'][target[i]-'a']==1e9) return -1;
            ans+=dis[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};

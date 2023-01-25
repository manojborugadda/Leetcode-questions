class Solution { //TC:O(N)  SC:O(N)
public:
    int n;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);
        bfs(edges,node1,dist1);
        bfs(edges,node2,dist2);

        int minDistNode = -1 , minDistTillNow = INT_MAX;
        for(int i = 0;i<n;i++) {
            int maxi = max(dist1[i],dist2[i]);
            if(minDistTillNow > maxi) {
                minDistTillNow = maxi;
                minDistNode = i;
            }
        }
        return minDistNode;
    }

     void bfs(vector<int>& edges, int startNode,vector<int>&dist) {
        queue<int>q;
        q.push(startNode);
        dist[startNode] = 0;//distance from any NODE to itself is ZERO
        vector<bool>visited(n,false);
        visited[startNode] = true;
        while(!q.empty()) {
            int u  = q.front();
            q.pop();
            //we would have iterated in the adjacency list but as in the question says each node has at most one outgoing edge.
            int v = edges[u];
            if(v != -1 and visited[v] == false) {
                visited[v] = true;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
     }
};

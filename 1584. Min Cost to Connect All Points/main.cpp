class Solution {//Time complexity: O(N2∗logN) for N = ps.length
public://SC:(N)
	int distance(vector<int> &pointA, vector<int> &pointB) {
		return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
	}
	int minCostConnectPoints(vector<vector<int>> &ps) {
		int n = ps.size(), mstWt = 0;
		vector<int> vis(n, 0);

        //min Heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});  // {wt, toNode}

        while( pq.size() ){
            auto [wt, node] = pq.top();
            pq.pop();

            if( vis[node] ) continue;
            mstWt += wt;
            vis[node] = 1;

            for(int i=0; i<n; i++){
                if( !vis[i] ) pq.push({distance(ps[node], ps[i]), i});
            }
        }
        return mstWt;
	}
};

class Solution {//TC:O(V+E) SC:O(V+E)
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>inDegree(numCourses,0);
        vector<int>ans;
        
    //adjacency list creation along with the InDegree vector
    for(auto i : prerequisites) {
        adj[i[1]].push_back(i[0]);
        inDegree[i[0]]++;
    }

    // performing TOPOLOGICAL sort
    queue<int>q;
    //pushing all the NODES whose inDegree is 0
    for(int i = 0;i<numCourses;i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    //performing BFS
    while(!q.empty()) {
        auto temp = q.front();
        ans.push_back(temp);
        q.pop();
        
        for(auto &x : adj[temp]) {
            inDegree[x]--;
            if(inDegree[x] == 0 ) {
                q.push(x);
            }
        }
    }
        return ans.size() == numCourses;
    }
};

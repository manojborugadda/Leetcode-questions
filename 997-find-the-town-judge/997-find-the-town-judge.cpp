class Solution { //TC:O(N) SC:O(N)
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Indegree of a node is the number of edges coming 'in' to that node.Similary outdegree is defined as the number of nodes going 'out' of that node.

        vector<int>outDegree(n+1,0);
        vector<int>inDegree(n+1,0);
        //In a Directd Graph each vertex has an Indegree and OutDegree
        for(int i = 0;i<trust.size();i++){
            outDegree[trust[i][0]]++;
            inDegree[trust[i][1]]++;
        }
        
        for(int i = 1;i<n+1;i++){
            if(outDegree[i] == 0 and inDegree[i] == n-1 ) {
                return i;
            }
        }
        //otherwise
        return -1;
    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(n == 1) return 0;
        if(edges.size() == 0) return -1;
        vector<int>inDegree(n,0);
        for(vector<int>vec : edges) {
            int a = vec[0];
            int b = vec[1];
            inDegree[b]++;
        }
        int count = 0;
        int idx ;
        for(int i =0;i<n;i++) {
            if(inDegree[i] == 0) {
                count++;
                idx = i;
            }
        }
        if(count > 1) return -1;
        if(count == 1) return idx;
        return 0;
    }
};

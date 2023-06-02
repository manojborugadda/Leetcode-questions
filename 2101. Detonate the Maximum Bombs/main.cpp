class Solution {//TC:O(N^2)  SC:O(N^2) + O(N)
public:
    void dfs(vector<int>&visited,vector<vector<int>>&temp,int &maxi,int &i) {
        visited[i] = 1;
        maxi++;
        for(int j = 0;j<temp[i].size();j++) {
            if(!visited[temp[i][j]]) {
                dfs(visited,temp,maxi,temp[i][j]);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>temp(n);
        for(int i = 0;i<n;i++) {
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r = bombs[i][2];
        for(int j = 0;j<n;j++) {
            if(i != j) {
                long long a = abs(x-bombs[j][0]);
                long long b = abs(y-bombs[j][1]);
                if(a*a + b*b <= r*r) {
                    temp[i].push_back(j);
                }
            }
        }
    }

    int res = INT_MIN;
    for(int i = 0;i<n;i++) {
        int max_bombs = 0;
        vector<int>visited(n,0);
        dfs(visited,temp,max_bombs,i);
        res = max(res,max_bombs);
    }
        return res;
    }
};

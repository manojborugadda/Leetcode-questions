class Solution {
public:
    vector<int>adj[100005];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0;i<manager.size();i++) {
            if(manager[i] != -1) {
                adj[manager[i]].push_back(i);
            } 
        }
        return dfs(headID,informTime);
    }

    int dfs(int headID,vector<int>& informTime) {
        int maxi = 0;//time needed to inform All Employees
        for(auto x: adj[headID]) {
            maxi = max(maxi , dfs(x,informTime));//taking max of (time needed for that node's Childrens)
        }
        return informTime[headID] + maxi;
    }
};

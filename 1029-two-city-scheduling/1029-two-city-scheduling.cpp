class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int>&a, const vector<int>&b){
            return (a[0]-a[1]) < (b[0]-b[1]);
        });
        
        int min_cost = 0;
        for(int i = 0;i<costs.size()/2;i++){
            min_cost += costs[i][0] + costs[costs.size()/2+i][1];
        }
        return min_cost;
    }
};
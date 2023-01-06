class Solution { //TC:O(nlogn)  SC:O(1)
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        if(n == 0) return 0;
        int ans = 0;
        sort(begin(costs),end(costs));
        for(int i = 0;i<n;i++) {
            if(costs[i] <= coins) {
                coins -= costs[i];
            }else {
                return i;
            }
        }
        return n;
    }
};

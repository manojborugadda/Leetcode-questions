class Solution {//TC:O(21 * 2*5000)  SC:O(21 * 2*5000)
public:
    int dp[20][10001];
    int recur(int idx , int diff , vector<int>& rods) {
        if(idx == rods.size()) {
            return diff == 0 ? 0 : -1e4;
        }
        if(dp[idx][diff+5000] != -1) return dp[idx][diff+5000];
        int ans1 = recur(idx+1,diff,rods);
        int ans2 = rods[idx] + recur(idx+1,diff + rods[idx] , rods);
        int ans3 = rods[idx] + recur(idx+1,diff-rods[idx],rods);
        return dp[idx][diff+5000] = max(ans1, max(ans2, ans3));
    }

    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        int ans =  recur(0,0,rods)/2;
        return ans;
    }
};

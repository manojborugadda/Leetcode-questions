class Solution {//TC:O(N*N) SC:O(N)
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0 , n = ages.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        vector<vector<int>>temp;
        for(int i =0;i<n;i++) {
            temp.push_back({ages[i],scores[i]});
        }
        sort(begin(temp),end(temp),greater<vector<int>>());

        for(int i=0;i<n;i++) {
            for(int j =i;j>=0;j--) {
                if(temp[i][1] <= temp[j][1]) {
                    dp[i] = max(dp[i],dp[j]+temp[i][1]);
                }
            }
            ans = max(ans,dp[i]);//taking the maximum of the 
        }
        return ans;
    }
};

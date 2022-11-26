class Solution {  //TC:O(NLOGN)   SC:O(N)
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>job;
        int n = profit.size();
        for(int i = 0;i<n;i++) {
            job.push_back({endTime[i],startTime[i],profit[i]});
        }
        
        sort(begin(job),end(job));  //sorting on the endingTIME
        
        vector<int>dp(n,0);
        dp[0] = job[0][2];  //profit is initially added to the DP[0]
        int ans = job[0][2];  //we initialise MAX_PROFIT as DP[0][2]
        for(int i = 1;i<n;i++) {  //TC:O(N)
            dp[i] = job[i][2];
            int end = binarySearch(job,i);
            if(end != -1) dp[i] += dp[end];
            dp[i] = max(dp[i],dp[i-1]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
    
    int binarySearch(vector<vector<int>>&job,int i) {  //TC:O(LOGN)
        int res = -1;
        int low = 0 , high = i-1;
        while(low <= high) {
             int mid = (high+low)>>1;
            if(job[mid][0] <= job[i][1]) {
                res = mid;
                low = mid+1;
            }else {
                high = mid-1;
            }   
        }
        return res;
    }
};
class Solution {//TC:O(N)+ recursive stack , SC:O(N)
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }

    long long solve(vector<vector<int>>& arr,int idx) {
        if(idx >= arr.size()) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        long sol = 0 , skip = 0;
        sol = arr[idx][0] + solve(arr, idx + arr[idx][1] + 1);
        skip = solve(arr,idx+1);
        return dp[idx] = max(sol,skip);
    }

};

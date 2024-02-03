class Solution {//tc:O(N^K)  sc:o(1n)
public:
    vector<int> dp;
    int solve(vector<int> &arr, int k, int ind){
        int n = arr.size(), mx = 0, ans = 0;
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solve(arr, k, i+1));
        }
        dp[ind] = ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(), -1);
        return solve(arr, k, 0);
    }
};

class Solution {//TC : O(n1 * n2 + n2 * log(n2)).
public:         //Space complexity: 2001 x 2001
    int sol(int i,int j,int prev,int &n1,int &n2,vector<int>&a1,vector<int>&a2,vector<vector<int>>&dp){
        if(i==n1) return 0;
        j=upper_bound(a2.begin(),a2.end(),prev)-a2.begin();
        if(dp[i][j]!=-1) return dp[i][j];
        int take =2001,nottake=2001;
        if(j<n2)
        take=1+sol(i+1,j+1,a2[j],n1,n2,a1,a2,dp);
        if(a1[i]>prev)
        nottake=sol(i+1,j,a1[i],n1,n2,a1,a2,dp);
        return dp[i][j]=min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n1=arr1.size(),n2=arr2.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        sort(arr2.begin(),arr2.end());
        int ans=sol(0,0,-1,n1,n2,arr1,arr2,dp);
        if(ans>=2001) return -1;
        return ans;
    }
};

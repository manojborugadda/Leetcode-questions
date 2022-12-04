class Solution {//TC:O(N)  SC:O(N)
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        vector<long long>prefix(n,0);
        
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++) {//prefix array
            prefix[i]  = prefix[i-1] + (long long)nums[i] ;
        }
        
        int minAvgDiff = INT_MAX; //minimum Avg Difference
        int ans = -1;
        for(int i = 0;i<n;i++) {
            int left = prefix[i] / (i + 1);
            int right = n - i - 1 > 0 ? ((prefix[n - 1] - prefix[i]) / (n - i - 1)) : 0 ;
            int mini = abs(left - right);
            if (mini < minAvgDiff) {
                minAvgDiff = mini;
                ans = i;
            }
        }
        return ans;
    }
};
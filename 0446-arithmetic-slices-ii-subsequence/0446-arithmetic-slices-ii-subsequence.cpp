class Solution {    //TC:O(N^2)  SC:O(N)
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        vector<unordered_map<long long int,long long int>>dp(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<i;j++) {
                long long int diff = (long long int)nums[i] - nums[j];
                if(dp[j].find(diff) == dp[j].end()) { //if the arithmetic subsequence is not found
                    ans += 0;
                    dp[i][diff] +=  1;//increment its FREQ initially
                } else {
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff] + 1;
                }
            }
        }
        return ans;
    }
};
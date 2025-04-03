class Solution {//TC:O(N)  SC:O(N)
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>rightMX(n,0),leftMX(n,0);
        rightMX[0] = nums[0] , leftMX[n-1] = nums[n-1];
        for(int i = 1;i<n;i++) {
            leftMX[i] = max(nums[i-1],leftMX[i-1]);
        }
        for(int i = n-2;i>=0;i--) {
            rightMX[i] = max(nums[i+1],rightMX[i+1]);
        }
        long long ans = 0;
        for(int j = 1;j<n-1;j++) {
            ans = max(ans, (long long)(leftMX[j] - nums[j]) * rightMX[j]);
        }
        return ans;
    }
};

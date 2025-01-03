class Solution {//TC:O(N) SC:O(N)
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long int>prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i =1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        int ans = 0;
        //(from index 0 to n-2) are considered.
        //checks splits even till n-1 index
        for(int i =0;i<n-1;i++) {
            if(prefixSum[i] >= prefixSum[n-1] - prefixSum[i]) {
                ans++;
            }
        }
        return ans;
    }
};

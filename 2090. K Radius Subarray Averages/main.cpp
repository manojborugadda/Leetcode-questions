class Solution {//TC:O(N)  SC:O(N)
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0) return nums;
        vector<int>ans(n,-1);
        if(n < 2*k+1) return ans;
        vector<long long>prefixSum(n,0);
        prefixSum[0] = nums[0];//first element
        for(int i = 1;i<n;i++) {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }

        for(int i = k;i<=n-k-1;i++) {
            int left_idx = i-k;
            int right_idx = i+k;
            long long sum = prefixSum[right_idx];
            if(left_idx > 0) {
                sum -= prefixSum[left_idx-1];
            }
            ans[i] = sum/(2*k+1);
        }
        return ans;
    }
};

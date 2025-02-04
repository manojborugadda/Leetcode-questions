class Solution {//TC:O(N)  sc:O(1)
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int sum = nums[0];
        int ans = 0;
        for(int i = 1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            }else {
                ans = max(sum,ans);
                sum = nums[i];
            }
            // cout<<ans<<endl;
            ans = max(sum,ans);
        }
        return ans;
    }
};

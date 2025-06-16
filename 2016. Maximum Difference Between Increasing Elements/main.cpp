class Solution {//TC:O(N)  SC:O(1)
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = -1;
        int n = nums.size();
        for(int i = 1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                maxi = max(maxi,(nums[i] - mini));
            }
            mini = min(mini,nums[i]);
        }
        return maxi;
    }
};

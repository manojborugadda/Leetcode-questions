class Solution {//TC;O(N)  SC:O(1)
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        // we are checking for strictly INCREASING from LEFT to RIGHT and save the max length
        int len = 1;//sub array of length ONE is itself is strictly increasing. so we initialised as 1 initially
        int n = nums.size();
        if(n == 1) return 1;
        int ans = 0;
        for(int i  = 1;i<n;i++) {
            if(nums[i] > nums[i-1]) {
                len++;
            }else {
                len = 1; // we reset to defualt value 1 when the longest subarray condition breaks
            }
            ans = max(ans,len);
        }


        // we are checking for strictly INCREASING from RIGHT to LEFT and save the max length
        // this checking indirectly checking the strictly DECREASING condition
        int len1 = 1;
        int ans1 = 0;
        for(int i  = n-1;i >=1;i--) {
        if(nums[i] < nums[i-1]) {
            len1++;
        }else {
            len1 = 1;
        }
        ans1 = max(ans1,len1);
    }

    return max(ans,ans1);

    }
};

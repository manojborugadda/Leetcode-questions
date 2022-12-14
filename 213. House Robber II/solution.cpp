class Solution {  //TC:O(N)  SC:O(N)
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());

        return max(helper(nums1) , helper(nums2));
    }

private:
        int helper(vector<int>& nums) {
            int n = nums.size();
            if( n == 0) return 0;
            if(n == 1) return nums[0];
            vector<int>dp(n+1,0);
            dp[0] = nums[0];
            dp[1] = max(nums[0],nums[1]);
            for(int i = 2;i<n;i++) {
                dp[i] = max(dp[i-2] + nums[i] , dp[i-1]);
            }
            return dp[n-1];
        }
};



// //another way of solving
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if( n == 0) return 0;
//         if(n == 1) return nums[0];
//         return max(helper(nums,0,n-1),helper(nums,1,n));
//     }

//     int helper(vector<int>& nums,int start,int end) {
//         int prevTwo = 0 , prevOne = 0 , maxi = INT_MIN;
//         for(int i = start;i<end;i++) {
//             maxi = max(prevTwo + nums[i] , prevOne);
//             prevTwo = prevOne;
//             prevOne = maxi;
//         }
//         return maxi;
//     }
// };

class Solution {  //    TC:O(N)  SC:O(1)
public:
                // using sliding window of variable length 
                //we have to find the maximum window size
    
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size() , ans  = 0 , j = 0 , num = 0;
        for(int i = 0;i<n;i++) {
            while( ( num & nums[i] ) != 0 ) {
                //unset the bits at that position until & of the two is not equal to 0 again
                num ^= nums[j++];
            }
            num |= nums[i]; //keep on setting the bits for that position in num
            ans = max(ans,i-j+1);
        }
        return ans;//maximum window size
    }
};
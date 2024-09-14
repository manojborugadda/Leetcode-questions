class Solution {//tc;O(n)  sc:o(1)
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        int ans = 1 , subarraylen = 0;
        // we can use the below c++ method for getting the MAXIMUM element in the vector
        // int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++) {
            maxi = max(maxi,nums[i]);
        }
        for(int num : nums) {
            if(num == maxi) {
                subarraylen++;
                ans = max(ans,subarraylen);
            }else {
                subarraylen = 0;
            }
        }
        return ans;
    }
};
//Find longest consecutive length of the maximum element of nums
//😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂😂

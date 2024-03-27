class Solution {//TC:O(N)  SC:O(1)
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {//sliding window problem
        int n = nums.size();
        int left = 0 , right = 0; //left pointer , right pointer
        int count = 0;
        int prod = 1;
        if(k <= 1) return 0;
        while(right < n) {
            prod = prod*nums[right];
            while(prod >= k) {
                prod = prod/nums[left++];
            }
            count += (right-left+1);// no.of subarrays ending at pointer RIGHT
            right++;
        }
        return count;
    }
};

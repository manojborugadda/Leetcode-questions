class Solution { // sliding window and Two Pointer approach
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, ans = 0, zero_count = 0;
        for(int j = 0;j<nums.size();j++){
            if(nums[j]==0) zero_count++;
            while(zero_count > k){ // if "zero count" is greater than "k", we  move "i" while checking if nums[i] is 0 are not and decreasing the zero count untill it equals K
                if(nums[i]==0) zero_count--;
                i++;
            }
            ans = max(ans,j-i+1); // taking the length of the the maximum number of consecutive 1's in the array
        }
        return ans;
    }
};

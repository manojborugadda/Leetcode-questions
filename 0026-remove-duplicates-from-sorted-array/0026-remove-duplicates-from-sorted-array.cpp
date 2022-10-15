class Solution {        //TC:O(N)  SC:O(1)
public://TWO POINTER APPROACH 
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int p1 = 0;
        for(int p2 = 1;p2<n;p2++) { 
                // If elements at p1 & p2 not equal, increment p1 and copy 
                // nums[p2] to nums[p1] so as to concentrate all unique 
                // elements in ascending order at the initial indices of the vector
            if(nums[p1]!=nums[p2]) {
                 p1++;
                 nums[p1] = nums[p2];
            }
        }
        return p1+1;
    }
};

//We are not allocating extra space for another array instead we are modifying the input array in-place with O(1) extra memory.


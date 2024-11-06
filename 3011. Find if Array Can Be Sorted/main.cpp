class Solution {//TC:O(N^2)  SC:O(1)
public:
    int getSetBits(int n) {//counting the no. of 1's in the binary representation of a NUMBER
        int count = 0;
        while(n != 0) {
            count += (n&1);
            n >>= 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {//usinng BUBBLE SORT
        int n = nums.size();
        for(int i =0 ;i<nums.size();i++) {
            for(int j =0;j< n-i-1;j++) {
                if(nums[j] > nums[j+1] and getSetBits(nums[j]) == getSetBits(nums[j+1]) ) {
                    swap(nums[j+1],nums[j]);
                }
            }
        }

        for(int i =0;i<n-1;i++) {//checking if the resulted vector is in INCREASING ORDER or not
            if(nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};

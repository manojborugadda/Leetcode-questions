class Solution {//TC:O(N)  SC:O(1)
public:
    void sortColors(vector<int>& nums) {
        int zeroPointer = 0;
        int twoPointer = nums.size()-1;
        int i = 0;
        while(i <= twoPointer) {
            if(nums[i]== 0 ) {
                swap(nums[i],nums[zeroPointer]);
                i++;
                zeroPointer++;
            }else if(nums[i] == 2) {
                swap(nums[i],nums[twoPointer]);
                twoPointer--;
            }else {
                i++;
            }
        }
    }
};

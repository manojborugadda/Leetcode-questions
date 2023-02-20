class Solution {
public://using BINARY SEARCH  TC:O(N)  SC:O(1)
    int searchInsert(vector<int>& nums, int target) {
        int i = 0,j = nums.size()-1;
        while(i <= j) {
            int mid = (i+j)>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]< target) {
                i = mid+1;
            }else if(nums[mid] > target) {
                j = mid-1;
            }
        }
        return i;
    }
};

//ONE LINER solution using LOWER BOUND

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         return  lower_bound(nums.begin(),nums.end(),target)-nums.begin();
//     }
// };

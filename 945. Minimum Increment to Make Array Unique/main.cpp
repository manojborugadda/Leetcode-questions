class Solution {//TC:O(nlogn) SC:O(1)
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int count = 0;
        for(int i =1;i<nums.size();i++) {
            if(nums[i] <= nums[i-1]) {
                count+= (nums[i-1]-nums[i]+1);
                nums[i] = nums[i-1]+1;
            }
        }
        return count;
    }
};

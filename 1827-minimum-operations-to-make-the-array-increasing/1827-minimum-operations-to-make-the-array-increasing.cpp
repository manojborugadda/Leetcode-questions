class Solution {
public:
    int minOperations(vector<int>& nums)
    {
      int count = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                int change = nums[i-1] - nums[i] +1;
                count = count + change;
                nums[i] = nums[i]+change;
            }
        }
        
        return count;
    }
};




//https://www.youtube.com/watch?v=ttznU-BTqTk

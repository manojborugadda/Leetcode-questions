class Solution {  // TC:O(N)  SC:O(1) as we are not using any extra space
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left_index = 0 , maxi = 0;
        int right_index = n-1 , mini = n-1;
        
        for(int i = 0;i<n;i++){
            // we are iterating from left to right direction to get the left_index
            if(nums[i] > nums[maxi]){
                maxi = i;
            }else if(nums[i] < nums[maxi]){
                left_index = i;
            }
            
            // iterating from Right to Left direction to get the Right_index
            if(nums[n-i-1] < nums[mini]){
                mini  = n-i-1;
            }else if(nums[n-i-1] > nums[mini]){
                right_index = n-i-1;
            }
        }
        
        if(left_index <= right_index){  
            return 0;
        }else
        {
            return left_index-right_index+1;
        }
        
    }
};
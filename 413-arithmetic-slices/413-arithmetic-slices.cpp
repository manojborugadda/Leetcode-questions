class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     if(nums.size() < 3 )return 0;
        int n  = nums.size();
        int sum  = 0, curr = 0;
        
        for(int i = 2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                curr += 1;
                sum = sum+curr;
            }
            else{
                     curr = 0;
                }
            }
        return sum;   
    }
};
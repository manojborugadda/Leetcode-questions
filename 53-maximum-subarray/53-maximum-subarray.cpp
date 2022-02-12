class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // using *******Kadane Algorithm***********
        
        int n = nums.size();
        int max_sum = INT_MIN;	//Initializing Maxsum variable = INT_MIN;
        int curr_sum = 0; //temporary storing the current sum
        
        for(int i=0;i<n;i++){
            curr_sum += nums[i];
            max_sum = max(curr_sum,max_sum);
            
            
//If our curr_sum becomes less than zero aka negative then when will again start from zero because taking that sum will decrease curr_sum.
            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        return max_sum;
    }
};
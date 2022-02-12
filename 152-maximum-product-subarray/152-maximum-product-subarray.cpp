class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        // we will check the max product from both sides of an array
          int n = nums.size();
        
        //prefix product max
        int max_prod = INT_MIN;
          int curr_prod = 1;
        for(int i=0;i<n;i++){
            curr_prod = curr_prod*nums[i];
            max_prod  = max(curr_prod,max_prod);
            
            if(nums[i]==0){
                curr_prod = 1;
            }
        }
        
 //[3 , -1 , 4]  this array can't give result if we just pass from front so we have to check from back too
        
        	 //suffix product max
        curr_prod = 1;
        for(int i=n-1;i>=0;i--){
            curr_prod = curr_prod*nums[i];
            max_prod  = max(curr_prod,max_prod);
            
            if(nums[i]==0){
                curr_prod = 1;
            }
        }
        
        return max_prod;
    }
};
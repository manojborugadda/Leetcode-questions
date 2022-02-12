class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {   if(k<=1) return 0;  // product cannot be less than 1
        int n = nums.size(); 
        int count = 0 , prod = 1 , j = 0;
     
        for(int i=0;i<n;i++){
                prod = prod * nums[i];
            while(prod >= k){
                prod = prod/nums[j];
                j++;
            }
            count = count+(i-j)+1;   
        }
     
        return count;
    }
};
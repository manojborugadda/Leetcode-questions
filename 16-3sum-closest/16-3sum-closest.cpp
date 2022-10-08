class Solution {        ///TC:O(N^2)  SC:O(1)
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums)); //sorting the VECTOR 
        
        int min_diff =INT_MAX , res = 0 , n = nums.size();
        
        for(int i = 0;i<n-2;i++) {
            //TWO POINTER APPROACH
            int left = i+1 , right = n-1;
            
            while(left < right) {
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(abs(target - sum ) < min_diff) {
                    min_diff = abs(target - sum );
                    res = sum;
                }
                if(sum > target ) {
                    right--;
                }else{
                    left++;
                }
            }
        }
        return res;
    }
};
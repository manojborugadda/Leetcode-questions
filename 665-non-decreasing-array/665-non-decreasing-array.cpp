class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int modified = 0; // intially we keep the "modified" or "changed" count as 0
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1])
            {
                modified++;
             
            if(modified > 1) return false;
            
            if(i<2 or (nums[i-2] <=nums[i]) ){  
                 nums[i-1] = nums[i];  // for example [ 4 2 3] ---becomes  [2 2 3]
            } 
            else{
                nums[i] = nums[i-1] ; // for an example [3 4 1] becomes [3 4 4]
            }       
        }
    }
       return true; 
    }
};
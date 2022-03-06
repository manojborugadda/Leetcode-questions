class Solution {
public:
    bool searchUtil ( vector<int> &nums , int target ) 
    {
        int low = 0 , high = nums.size()-1 ; 
        while ( low <= high )
        {
            // finding the mid
            int mid = ( (high-low)/2) + low ; 
           
            // target found
            if ( nums[mid] == target ) return true ; 
            
            // cant determine which part is sorted 
            if ( nums[low] == nums[mid] and nums[mid] == nums[high] ) 
            {
                low++ , high-- ; 
                continue ;
            }
             // low to mid is sorted 
            if ( nums[low] <= nums[mid] )
            {
                if ( target >= nums[low] and target <= nums[mid] ) high = mid-1  ;
                else low = mid+1 ; 
            }
            // mid to high is sorted 
            else
            {
                if ( target >= nums[mid] and target <= nums[high] ) low = mid+1 ;
                else high = mid-1 ; 
            }
        }
        return false ; 
    }
    bool search(vector<int>& nums, int target) {
        return searchUtil ( nums , target ) ;
    }
};
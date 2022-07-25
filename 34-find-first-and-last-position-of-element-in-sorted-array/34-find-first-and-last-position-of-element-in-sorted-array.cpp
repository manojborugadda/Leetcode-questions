class Solution {  ///TC:O(Logn)
public:
    
    //modified BINARY SEARCH 
    int binarySearch(vector<int>& nums, int target, bool leftBias){
        int left = 0 , right = nums.size()-1;
        //Initially k is kept -1  becuase if target is not found in the array, return [-1, -1].
         int k = -1;
        while(left <= right){
            int mid = (left+right)>>1;
            if(nums[mid] < target){
                left = mid+1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{///---------------from here the actual logic comes into picture
                k  = mid;
                if(leftBias == true){
                    right = mid-1;
                }else{//     leftBias == false
                    left = mid+1;
                }
            }
        }
        return k;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int starting = binarySearch(nums,target,true); ///for starting index of given target
        int ending =    binarySearch(nums,target,false);//for ending index of given target
        return { starting , ending };///answer vector
    }
};
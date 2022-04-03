
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         bool val=next_permutation(nums.begin(),nums.end());
//         if(val==false)
//         {
//             sort(nums.begin(),nums.end());
//         }
//     }
// };


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , index1 , index2;
        for(index1  = n-2 ; index1 >= 0 ; index1--){
            if(nums[index1] < nums[index1+1]){
                break;  /// thus we got the index1
            }
        }
        
        if(index1 < 0){
            reverse(nums.begin(),nums.end());
        }
        else{  //  index1 > 0
            for(index2 = n-1;index2 > index1;index2--){
                if(nums[index2]>nums[index1]){
                    break; /// here we got the index2
                }
            }
            
            swap(nums[index1],nums[index2]);
            reverse(nums.begin()+index1+1,nums.end());
        }
        
     }
};
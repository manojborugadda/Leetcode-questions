// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         int count=0;
//     for(auto x:nums)
//     {
//         if(mp[k-x]) // if it is present in the MAP
//         {
//             //// removing the pairs from the MAP
//             mp[(k-x)]--; 
//             mp[x]--;
            
//             count++;
//         }
//         mp[x]++;
//     }
//         return count;
//     }
// };

//using the TWO POINTER approach

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       int i = 0, j = nums.size()-1;
        int count = 0;
        sort(nums.begin(),nums.end());  // sorting the array 
        while(i<j){
            if(nums[i]+nums[j]==k){
                count++;
                i++;j--;
            }else if(nums[i]+nums[j] < k){
                i++;
            }else{
                j--;
            }
        }
        return count;
    }
};
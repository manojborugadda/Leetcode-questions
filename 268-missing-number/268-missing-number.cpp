// class Solution {  // TC:O(N) SC:O(N) because we are using hashmap
// public:
//         int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>mp;
//         for(auto x: nums){
//             mp[x]++;
//         }
        
//         for(int i = 0;i<=n;i++){
//             if(mp[i]==0){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };



 class Solution {  // TC:O(N) SC:O(1)
 public:    
        int missingNumber(vector<int>& nums) {
            int ans,sum = 0 ;
            int n = nums.size();
            int total = n*(n+1)/2;  // sum of all N natural numbers
            for(auto x:nums){
                sum = sum+x; // sum of all elements in the array
            }
            
            ans = total-sum; // here we get the missing element by subtracting 
            return ans;
        }
    };

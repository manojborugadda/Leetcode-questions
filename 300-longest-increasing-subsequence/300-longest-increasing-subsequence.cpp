/*
class Solution {  // TC:O(N*2)  SC:O(N)--- as we are using extra space for DP
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1; // length of the "longest strictly increasing subsequence."( "LIS")
        vector<int>dp(n,1);  // DP of size "nums"
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j]){ //if the present value is greater than the previous value
                    dp[i] = max( dp[i] , dp[j]+1 );
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

*/

//////using the algorithm that runs in O(n log(n)) time complexity

class Solution {  // TC:O(Nlogn)  SC:O(N)
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int i = 0;i<n;i++){
            auto itr = lower_bound(res.begin(),res.end(),nums[i]);
            if(itr == res.end()){// itr pointer reaches the end of the Vector
                //we push it into the vector
                res.push_back(nums[i]);
            }else{
                *itr = nums[i];  // if we got the element which is slightly greater than or Equal to nums[i]  we change the value at 'itr' and replace with nums[i]
            } 
        }
        return res.size(); // which actually has the lenght of the longest strictly increasing subsequence 
    }
};
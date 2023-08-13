class Solution {  //TC:O(N)  SC:O(N)
public:
    bool memoiz(int idx , vector<int>&arr , vector<int>&dp) {
        if(idx >= arr.size()) {
            return true;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }
        bool check = false; // checks if the partitioning is VALID at all conditons below

        //condition for 2 Consecutive Elements
        if(idx + 1 < arr.size() and arr[idx] == arr[idx+1]) {
            check |= memoiz(idx+2 , arr , dp);
        }
        //for 3 Consecutive Elements are same
        if(idx+2 < arr.size() and arr[idx] == arr[idx+1] and arr[idx] == arr[idx+2]) {
            check |= memoiz(idx+3 , arr , dp);
        }

        ///for 3 consecutive increasing elements
        if(idx+2 < arr.size() and arr[idx]  + 1 == arr[idx+1] and arr[idx+1] + 1  == arr[idx+2]) {
            check |= memoiz(idx+3 , arr , dp);
        }
        return dp[idx] = check;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return memoiz(0,nums,dp);
    }
};

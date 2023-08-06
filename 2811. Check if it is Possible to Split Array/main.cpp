
/* Approach 2: Recursion + Memo
Try all partitions
Memoize already calculated subproblems
Time : O(n^2)     // n^2 states
Space : O(n^2)    // dp vector
*/

class Solution {
public:
    bool isValid(int &start, int &end, vector<int> &nums, int &m){
        int sum = 0;
        for (int i=start; i<=end; i++)
            sum += nums[i];
        return (sum >= m);
    }
    bool f(int start, int end, vector<int>&nums, int &m, vector<vector<int>> &dp){
        // base condition
        if (start == end)
            return true;
        
        // check if given subarray is valid
        if (!isValid(start, end, nums, m)) 
            return false;
        
        // already calculated
        if(dp[start][end] != -1)
            return dp[start][end];

        //try all partitions for this subarray
        bool res = false;
        for (int i=start; i<end; i++){
            bool left = f(start, i, nums, m, dp);
            bool right = f(i+1, end, nums, m, dp);
            if (left && right){
                res = true;
                break;
            }
        }
        return dp[start][end] = res;
    }

    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n <= 2) return true;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, nums, m, dp);
    }
};

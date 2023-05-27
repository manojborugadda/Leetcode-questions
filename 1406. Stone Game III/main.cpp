class Solution {//TC;O(N)  SC:O(N)
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),INT_MAX);//we used INT-MAX beacuase we will be taking the diff of ALICE and BOB and diff could not be INT_MAX in general
        int value = memoization(stoneValue,dp,0);
        if(value > 0) {
            return "Alice";
        }else if(value < 0) {
            return "Bob";
        }else {
            return "Tie";
        }
    }

    int memoization(vector<int>&stoneValue,vector<int>&dp,int index) {
        int n = stoneValue.size();
        if(index >= n) return 0;
        if(dp[index] != INT_MAX) return dp[index];
        int takeOne  = stoneValue[index]  - memoization(stoneValue,dp,index+1);
        int takeTwo = INT_MIN;
        if(index+1 < n) takeTwo =  stoneValue[index] + stoneValue[index+1]  - memoization(stoneValue,dp,index+2);
        int takeThree = INT_MIN;
        if(index+2 < n) takeThree = stoneValue[index] + stoneValue[index+1] +  stoneValue[index+2] - memoization(stoneValue,dp,index+3);
        return dp[index] = max({takeOne,takeTwo,takeThree});

    }
};

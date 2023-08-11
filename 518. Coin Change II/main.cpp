class Solution {//TC:O(N * AMOUNT)  SC:O(N * AMOUNT)
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount+1, 0);

        dp[0]=1;

        for(int c:coins){

            for(int i=c; i<=amount; i++)

                    dp[i]+=dp[i-c];

        }
        return dp[amount]; 
    }
};

class Solution {
public:
    int MOD = 1e9+7;
    int solve(string &s, int k, int idx, vector<int>&dp) {
        if (idx >= s.size()) {
            return 1;
        }
        if (s[idx] == '0') {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ways = 0;
        long currNum = 0;

        for (int i = idx; i < s.size(); i++) {
            currNum = currNum*10 + s[i]-'0';
            if (currNum > k) {
                break;
            }
            ways = (ways + solve(s, k, i+1, dp))%MOD;
        }
        return dp[idx] = ways;
    }

    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(), -1);
        return solve(s, k, 0, dp);
    }
};

/**
**
for each character we have choices
1.INCLUDE the char in currNum/subString
2.START new substring from char

*/

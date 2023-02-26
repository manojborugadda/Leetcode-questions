class Solution { //TC:O(N^3)  SC:O(N^2) //2D DP kind of problem
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        int m = word1.size() , n = word2.size();
        memset(dp,-1,sizeof(dp));
        return recur(word1,word2,m,n);
    }

    int recur(string s1,string s2,int i1,int i2) {
        if(i1==0) return i2;
        if(i2==0) return i1;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s1[i1-1] == s2[i2-1]) return dp[i1][i2] = recur(s1,s2,i1-1,i2-1);

        //if any of the above not happens we do the 3 OPERATIONS
        
        //  Insert a character
        int ins = 1 + recur(s1,s2,i1,i2-1);
        //Delete a character
        int del = 1 + recur(s1,s2,i1-1,i2);
        //Replace a character
        int repl = 1 + recur(s1,s2,i1-1,i2-1);
        return dp[i1][i2] = min(ins, min(del,repl) );
    }
};

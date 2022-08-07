class Solution {  //TC:O(N) SC:O(N)
public:
    int countVowelPermutation(int n) {
        // dp[i][j] -> stores number of strings of length=i starting from jth vowel
        long long int dp[n][6];
       dp[0][0]=dp[0][1]= dp[0][2]=dp[0][3]=dp[0][4]=dp[0][5]= 1;
        
        /*
        1. a-->e
        2. e--> a or i
        3. i--> a,e,o,u
        4. o--> i,u
        5. u-->a
        
        same here also lets assume a =1 , e = 2 , i = 3, o = 4 , u = 5
        
        1->2
        2->1,3
        3-> all except 3 itself
        4->3,5
        5->1
        */
        long long int md = 1e9+7;
        long long int ans = 0;
        for(int i = 1;i<n;i++){  
            dp[i][1]=dp[i-1][2];
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%md;
            dp[i][3]=(dp[i-1][1]+dp[i-1][2] + dp[i-1][4]+dp[i-1][5])%md;
            dp[i][4]=(dp[i-1][3]+dp[i-1][5])%md;
            dp[i][5]=dp[i-1][1];
            }
            ans = (dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4]+dp[n-1][5])%md;
            return ans;
    }
};
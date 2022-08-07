https://www.youtube.com/watch?v=VUVpTZVa7Ls
​
dp[i][j] -> stores number of strings of length=i starting from jth vowel
```
```
```
​
class Solution {
public:
int countVowelPermutation(int n) {
long long int dp[n][6];
dp[0][0]=dp[0][1]= dp[0][2]=dp[0][3]=dp[0][4]=dp[0][5]= 1;
/*
1->2
2->1,3
3-> all-{3}
4->3,5
5->1
*/
long long int md=1e9+7;
long long int ans=0;
for(int i=1;i<n;i++)
{
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
```
```
```
​
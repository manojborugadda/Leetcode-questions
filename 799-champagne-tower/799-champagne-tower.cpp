class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[101][101] = {0};
        dp[0][0] = poured;         //// initialize the first row with poured champagne 
        for(int i = 0;i<=query_row;i++){     // for each row
            for(int j = 0;j<=i;j++){  // for each glass
                double x = (dp[i][j] - 1)/2.0;
                if(x>0){
                    dp[i+1][j] += x;
                    dp[i+1][j+1] += x;
                }
            }
        }
        
        return min(1.0,dp[query_row][query_glass]);  //flow>=1 => glass is full
    }
};
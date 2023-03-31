class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1000000000 + 7; // define a constant for modulo arithmetic
        int rows = pizza.size(); // get the number of rows in the pizza
        int cols = pizza[0].size(); // get the number of columns in the pizza
        int dp[55][55][11] = {}; // initialize a 3D array to store the number of ways to cut the pizza
        int cnt[55][55] = {}; // initialize a 2D array to store the number of 'A' toppings in each sub-rectangle

        // calculate the number of 'A' toppings in each sub-rectangle of the pizza
        for(int i = 1; i <= rows; i++)
            for(int j= 1; j <= cols; j++){
                cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + (pizza[rows-i][cols-j] == 'A' ? 1 : 0);
            }

        // initialize the dp array for the base case of cutting the pizza into 0 pieces
        for(int i = 0; i <= rows; i++) dp[i][0][0] = 1;

        // iterate over the dp array and update it based on the number of 'A' toppings in each sub-rectangle
        for(int i = 0; i <= rows; i++)
            for(int j = 0; j<= cols; j++)
                for(int p = 0; p < k; p++)
                    if(dp[i][j][p]){
                        // iterate over the rows and update the dp array
                        for(int ii = i+1; ii <= rows; ii++)
                            if(cnt[ii][j] - cnt[i][j] > 0)
                                dp[ii][j][p+1] = (dp[ii][j][p+1] + dp[i][j][p]) % mod;
                        // iterate over the columns and update the dp array
                        for(int jj = j+1; jj <= cols; jj++)
                            if(cnt[i][jj] - cnt[i][j] > 0)
                                dp[i][jj][p+1] = (dp[i][jj][p+1] + dp[i][j][p]) % mod;
                    }
        return dp[rows][cols][k]; // return the number of ways to cut the entire pizza into k pieces
    }
};

class Solution {
public:
    vector<vector<int>>serves = { {100,0} , {75,25} , {50,50} , {25,75} };
    vector<vector<double>>dp;

    double recur(double a , double b) {
        //base conditions
        if(a <= 0 and b <= 0) {
            return 0.5;
        }
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;

        if(dp[a][b] != -1.0) {
            return dp[a][b];
        }

        double probability = 0.0;
        for(auto &serve : serves) {
            int a_new = serve[0];
            int b_new = serve[1];
            probability += 0.25 * recur(a - a_new , b - b_new);
        }
        return dp[a][b] =  probability;
    }
    double soupServings(int n) {
        if( n >= 5000) {
            return 1.0;
        }
        dp.resize(n+1,vector<double>(n+1,-1));
        return recur(n,n);
    }
};



/*
Reason why n is taken as >= 5000 gives 1 as probability -
According to question, B doesn't have the way to remove 100ml directly but have which means for large value of n, it is a more likely scenario that A is exhausted before B and if you find the probability using code, you will find that near 5000 the probability approaches to 1. Where clearly show that A is more likely to exhaust before B.

*/

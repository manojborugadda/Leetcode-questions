class Solution {// TC:O(M*N*FUEL)  M-- START SIZE , N -- INNER FOP-LOOP 
public:
    int dp[101][201]; //SC:O(101 * 201)
    int MOD = 1e9+7;
    int recur(int start , int finish,vector<int>& locations,int fuel) {
        if(fuel <= 0) {
            return start == finish ? 1 : 0;
        }
        //here changing variables are START , FUEL;
        if(dp[start][fuel] != -1) {
            return dp[start][fuel];
        }

        int ans = 0;
        if(start == finish) ans = 1;
        //traversing all the possible city locations 
        for(int i = 0;i<locations.size();i++) {                         //TC:O(N)
            if(i != start and abs(locations[start]-locations[i]) <= fuel) {
                ans = (ans%MOD + recur(i,finish,locations,fuel - abs(locations[start]-locations[i]))%MOD) %MOD;
            }
        }
        return dp[start][fuel] = ans%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return recur(start,finish,locations,fuel);
    }
};

class Solution {//TC:O(N^2) SC:O(N^2)
public:
    int n;
    unordered_map<int,int>map;
    int dp[2001][2001];
    bool memoization(int currStoneIdx , int prevJump ,vector<int>& stones) {

        //if the frog is on the last stone
        if(currStoneIdx == n-1) return true;


        if(dp[currStoneIdx][prevJump] != -1) {
            return dp[currStoneIdx][prevJump];
        }

        bool result = false;

        // checking for k-1, k, k+1
        for(int nextJump = prevJump-1;nextJump <= prevJump + 1;nextJump++) {
            //checking if the jump is VALID
            if(nextJump > 0) {
                int nextStone = stones[currStoneIdx] + nextJump;
                if(map.find(nextStone) != map.end()) {// if next stone is present in the map
                    result |= memoization(map[nextStone] ,nextJump , stones);
                }
            }
        }
        return  dp[currStoneIdx][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        // checking if Initially the frog is on the first stone and assumes the first jump must be 1 unit.
        if(stones[1] != 1) return false; 
        for(int i = 0;i<stones.size();i++) {// storing all the stones with thier indexes
            map[stones[i]] = i;
        }
        memset(dp,-1,sizeof(dp));
        return memoization(0,0,stones);
    }
};

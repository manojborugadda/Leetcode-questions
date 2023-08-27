class Solution {//TC:O(N)  SC:O(1)
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0 , rCount = 0 , underscoreCount = 0;
        for(int i = 0;i<moves.length();i++) {
            if(moves[i] == 'L') lCount++;
            else if(moves[i] == 'R') rCount++;
            else underscoreCount++;
        }
        return max(lCount , rCount) + underscoreCount - min(lCount , rCount);
    }
};

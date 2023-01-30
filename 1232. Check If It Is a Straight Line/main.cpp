#define inf 1000000007
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        double x = coordinates[1][0] - coordinates[0][0];
        double y = coordinates[1][1] - coordinates[0][1];
        double m;
        if(x == 0) m = inf; //if the denominator is ZERO we return the max value possible
        else m = y / x;
        for(int i = 0; i < coordinates.size() - 1; i++) {
            double dx = coordinates[i + 1][0] - coordinates[i][0];
            double dy = coordinates[i + 1][1] - coordinates[i][1];
            double slope;
            if(dx == 0) slope = inf;
            else slope = dy / dx;
            if(slope != m) return false;
        }
        return true;
    }
};

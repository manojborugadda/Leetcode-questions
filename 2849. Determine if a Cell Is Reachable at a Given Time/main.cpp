class Solution {//TC:O(1)  SC:O(1)
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x_diff  = abs(sx-fx) , y_diff = abs(sy-fy);
        if(x_diff == 0 and y_diff == 0 and t == 1){
            return false;
        }
        return min(x_diff , y_diff ) + abs(x_diff - y_diff) <= t;
    }
};

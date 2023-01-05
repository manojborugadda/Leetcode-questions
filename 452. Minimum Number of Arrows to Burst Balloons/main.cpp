class Solution {//TC:O(nlogn)  SC:O(1)
public:
static bool compare(vector<int>&a,vector<int>&b) {
    return a[1] < b[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(begin(points),end(points),compare);
        int arrows = 1;//initially no.of arrows is 1 as we have to burst the baloon
        int last = points[0][1];
        //for overlapping points we use one arrow to burst
        for( int i = 1;i<points.size();i++) {
            if(points[i][0] > last) {//if this condition becomes true it means overlapping not happening
                arrows++;
                last = points[i][1];//we update the last variable if overlapping not happens
            }
        }
        return arrows;
    }
};

//[[1,6],[2,8],[7,12],[10,16]]

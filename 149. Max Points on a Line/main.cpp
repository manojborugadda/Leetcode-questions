class Solution {//TC:O(N^2) SC:O(N)
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;//// if there is only one point, the max points will be 1
        int maxPoints = 2;//if there are more points, the max will be at least 2
        for(int  i = 0;i<n-1;i++) {
            map<double,int>map;
            for(int j = 0;j<n;j++) {
                if(i == j) {
                    continue;
                }

                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                //calculating the slope
                double tangent = atan2((y2-y1),(x2-x1));
                map[tangent]++;//increasing the count of that slope
                maxPoints = max(maxPoints,map[tangent]+1);
            }
        }
        return maxPoints;
    }
};

class Solution {
public:
    //typedef vector<int> vec;
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            double area = 0.5 * abs(
                points[i][0] * (points[j][1] - points[k][1]) +
                points[j][0] * (points[k][1] - points[i][1]) +
                points[k][0] * (points[i][1] - points[j][1])
            );
            ans = max(ans, area);
        }
    }
}
        return ans;
    }
};

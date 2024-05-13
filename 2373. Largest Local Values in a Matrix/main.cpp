class Solution {//TC:O(N^2)  SC:O(1)
public:
    int largestValue(vector<vector<int>>& grid, int r, int c) {
        int maxValue = 0;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                maxValue = max(maxValue, grid[i][j]);
            }
        }

        return maxValue;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                ans[i][j] = largestValue(grid, i, j);
            }
        }
        return ans;
    }
};

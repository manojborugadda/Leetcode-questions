class Solution {//TC:O(N)  SC:O(N)
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>>diff(m,vector<int>(n,0));
      vector<int>RowOnes(m,0);
      vector<int>ColOnes(n,0);
      for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
              if(grid[i][j] == 1) {
                RowOnes[i] += 1;
                ColOnes[j] += 1;
              }
          }
      }

      for(int i = 0;i<m;i++) {
          for(int j =0;j<n;j++) {
              int onesRowi = RowOnes[i];
              int onesColj = ColOnes[j];
              int zerosRowi = m - onesRowi;
              int zerosColj = n - onesColj;
              diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
          }
      }
      return diff;
    }
};

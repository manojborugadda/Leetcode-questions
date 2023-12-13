class Solution {//TC:O(n*m)  SC:O(1)
public:
    int numSpecial(vector<vector<int>>& mat) {
       int m = mat.size();
       int n = mat[0].size();
       vector<int>row(m,0);//no.of 1s in a row
       vector<int>col(n,0);// no.of 1s in column
       for(int i = 0;i<m;i++) {
           for(int j = 0;j<n;j++) {
               if(mat[i][j] == 1) {
                   row[i]++;
                   col[j]++;
               }
           }
       }

       int result = 0;
       for(int r =0;r<m;r++) {
           for(int c = 0;c<n;c++) {
               if(mat[r][c] == 1 and row[r] == 1 and col[c] == 1) {
                   result++;
               }
           }
       }
       return result;
    }
};

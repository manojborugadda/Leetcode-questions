class Solution { //TC:O(N) SC:O(1)
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
           int m = matrix[0].size();
           int n = matrix.size();
           for(int row = n-2;row >= 0;row--) {
               for(int col = 0;col < m ; col++) {
                   if(col == 0) {
        //if column is first column , we have TWO choices TOP, RIGHT Diagonal TOP
                       matrix[row][col] += min(matrix[row+1][col],matrix[row+1][col+1]);
                   }else if(col == m-1) {
                       //if column is last column,we have TWO choices TOP,LEFT Diagonal TOP
                        matrix[row][col] += min(matrix[row+1][col],matrix[row+1][col-1]);
                   }else {
//if column is MIDDLE one then we have 3 choices TOP,LEFT Diagonal TOP , RIGHT Diagonal TOP
                    int a = matrix[row+1][col];
                    int b = matrix[row+1][col+1];
                    int c = matrix[row+1][col-1];
                    int mini = INT_MAX;
                    if(a < mini) mini = a;
                    if(b < mini) mini = b;
                    if(c < mini) mini  = c;
                    matrix[row][col] += mini;
                   }
               }
           }
//in the first row we have the minimum sum of falling path which we calculated from BOTTOM TO TOP 
 //returning the minimum of the accumulated sum that is present in first row (0th index)
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
